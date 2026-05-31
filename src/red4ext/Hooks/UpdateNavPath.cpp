#include <Registrar.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/MinimapContainerController.hpp>
#include "CyberpunkMod.hpp"
#include "InWorldNavigation.hpp"

// 3797170204 (this, context, type, widgetRef)
// void game::ui::MinimapContainerController::UpdateGPSPath(ink::IWidgetController::UpdateContext const &, game::gps::ETargetType, ink::LinePatternWidgetReference const &)

// could use 1268721260 (this, type, data)
// void game::ui::MappinsContainerController::OnGPSPathChanged(game::gps::ETargetType, game::gps::IListener::PathData const &)

// 3770693656
// void game::ui::MinimapContainerController::UpdateGPSPath(struct ink::IWidgetController::UpdateContext const &,enum game::gps::ETargetType,struct ink::LinePatternWidgetReference const &)

// 3637917225
// UpdateFromPoints(game::ui::MinimapContainerController *this, DynArray<Vector4> *points, __int64 linePatternWidgetRef)

REGISTER_HOOK_HASH(void, 3770693656, UpdateNavPath, 
    RED4ext::game::ui::MinimapContainerController *mmcc, 
    __int64 updateContext, 
    unsigned __int8 targetType,
    RED4ext::ink::WidgetReference *widgetRef
  ) {
  UpdateNavPath_Original(mmcc, updateContext, targetType, widgetRef);

  auto rtti = RED4ext::CRTTISystem::Get();
  if (mmcc->GetType() == rtti->GetClass("gameuiMinimapContainerController")) {
    // auto profiler = CyberpunkMod::Profiler("UpdateNavPath", 5);
    auto fnp = InWorldNavigation::GetInstance();
    // The game's UpdateGPSPath signature delivers targetType as a 1-byte
    // enum (unsigned __int8), but the Redscript-side Update(Int32) expects
    // a 4-byte value. Passing &targetType directly would have the Redscript
    // VM read 3 bytes of stack garbage in the upper bits. Widen to int32_t
    // locally so the address we pass points at the full 4 bytes.
    int32_t targetTypeAsInt32 = static_cast<int32_t>(targetType);
    auto args = RED4ext::CStackType(rtti->GetType("Int32"), &targetTypeAsInt32);
    auto stack = RED4ext::CStack(fnp, &args, 1, nullptr);
    auto update = rtti->GetClass("InWorldNavigation")->GetFunction("Update");
    if (update)
      update->Execute(&stack);
    // auto avg = profiler.End();
    // if (avg) {
      // spdlog::info("Average InWorldNavigation loop time: {}", avg);
    // }
  }
}
