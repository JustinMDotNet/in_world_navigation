#include <RedLib.hpp>

struct InWorldNavigation : RED4ext::IScriptable {
  static RED4ext::Handle<InWorldNavigation> GetInstance();

  // Detach the file-scope singleton handle before the DLL is unloaded.
  // ~Handle()'s automatic destructor would call DecRef on a RefCnt that
  // lives in game-managed memory; whether that memory is still valid by
  // the time C++ runs DLL static destructors is uncertain (see
  // InWorldNavigation.cpp Shutdown comment), and historical exit-crash
  // reports (#27/#35/#43) suggest it isn't reliable. Shutdown bypasses
  // DecRef entirely by zeroing the handle's pointers; SharedPtrBase's
  // `if (refCount)` guard makes the later automatic destruction a no-op.
  // Call this from RED4EXT_C_EXPORT Main's Unload handler AFTER hooks
  // have been detached, so no game thread can race in via GetInstance().
  static void Shutdown();

  RTTI_IMPL_TYPEINFO(InWorldNavigation);
  RTTI_IMPL_ALLOCATOR();
  
  virtual bool CanBeDestructed() override {
    return false;
  }
};

RTTI_DEFINE_CLASS(InWorldNavigation, { 
  RTTI_METHOD(GetInstance); 
});