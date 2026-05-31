// Captures the "root state" (e.g. n"Quest", n"Gigs", n"FastTravel") computed
// by the game's QuestMappinController for the currently-tracked quest and POI
// mappins, and stores it on the InWorldNavigation singleton so that the FX
// renderer can pick the right color variant for the in-world arrows.
//
// Uses @wrapMethod so it composes cleanly with other mods that also extend
// QuestMappinController.ComputeRootState.

@wrapMethod(QuestMappinController)
protected func ComputeRootState() -> CName {
  let state = wrappedMethod();
  if IsDefined(InWorldNavigation.GetInstance().questMappin) && this.m_mappin == InWorldNavigation.GetInstance().questMappin {
    InWorldNavigation.GetInstance().questState = state;
  }
  if IsDefined(InWorldNavigation.GetInstance().poiMappin) && this.m_mappin == InWorldNavigation.GetInstance().poiMappin {
    InWorldNavigation.GetInstance().poiState = state;
  }
  return state;
}
