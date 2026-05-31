#include "InWorldNavigation.hpp"

RED4ext::Handle<InWorldNavigation> handle;

RED4ext::Handle<InWorldNavigation> InWorldNavigation::GetInstance() {
  if (!handle.instance) {
    auto rtti = RED4ext::CRTTISystem::Get();
    spdlog::info("[RED4ext] New InWorldNavigation Instance");
    auto instance = reinterpret_cast<InWorldNavigation *>(rtti->GetClass("InWorldNavigation")->CreateInstance());
    handle = RED4ext::Handle<InWorldNavigation>(instance);
  }

  return handle;
}

void InWorldNavigation::Shutdown() {
  // Bypass ~Handle() entirely. The destructor would call DecRef ->
  // InterlockedExchangeAdd on the RefCnt block, which lives in
  // game-managed memory. Whether that memory is still alive at
  // EMainReason::Unload is genuinely unverifiable statically — the SDK
  // expects Unload to be a safe place to release game-owned refs, but
  // historical RED4ext mods (and Main.cpp's own pre-existing comment in
  // the Unload case) treat it as "game memory is already gone". Rather
  // than gamble on which one is true, zero the handle's pointers
  // directly. SharedPtrBase::DecRef() is guarded by `if (refCount)`, so
  // the file-scope `handle`'s eventual automatic destruction at DLL
  // unload becomes a true no-op.
  //
  // Cost: we leak one strong-ref + one weak-ref on the singleton.
  // CanBeDestructed() returns false anyway (defense in depth), so even
  // if the game's own DecRef brought the count to zero, no destructor
  // would run. The "leak" is recovered when the OS reclaims the
  // process's memory at exit.
  handle.instance = nullptr;
  handle.refCount = nullptr;
}