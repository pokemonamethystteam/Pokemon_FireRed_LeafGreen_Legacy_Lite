FiveIsland_WaterLabyrinth_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, FiveIsland_WaterLabyrinth_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, FiveIsland_WaterLabyrinth_OnTransition
	.byte 0

FiveIsland_WaterLabyrinth_OnLoad::
	goto_if_eq VAR_KYOGRE_LOCATION, 1, FiveIsland_WaterLabyrinth_EventScript_SetUpKyogre
	goto FiveIsland_WaterLabyrinth_EventScript_SetUpClearKyogre
	end

FiveIsland_WaterLabyrinth_EventScript_SetUpKyogre::
	goto_if_set FLAG_CAUGHT_KYOGRE, FiveIsland_WaterLabyrinth_EventScript_SetUpClearKyogre
	goto_if_set FLAG_KYOGRE_FLED, FiveIsland_WaterLabyrinth_EventScript_SetUpClearKyogre
	clearflag FLAG_HIDE_KYOGRE
	setflag FLAG_HIDE_KYOGRE_NPC
	end

FiveIsland_WaterLabyrinth_EventScript_SetUpClearKyogre::
	clearflag FLAG_HIDE_KYOGRE_NPC
	setflag FLAG_HIDE_KYOGRE
	end

FiveIsland_WaterLabyrinth_OnTransition::
	goto_if_eq VAR_KYOGRE_LOCATION, 1, FiveIsland_WaterLabyrinth_EventScript_TestWeather
	end

FiveIsland_WaterLabyrinth_EventScript_TestWeather::
	goto_if_set FLAG_CAUGHT_KYOGRE, FiveIsland_WaterLabyrinth_EventScript_SetUpClearKyogre
	goto_if_set FLAG_KYOGRE_FLED, FiveIsland_WaterLabyrinth_EventScript_SetUpClearKyogre
	removeobject LOCAL_ID_LABYRINTH_WITNESS_1
	removeobject LOCAL_ID_LABYRINTH_WITNESS_2
	setweather WEATHER_DOWNPOUR
	fadenewbgm MUS_SEVII_DUNGEON
	savebgm MUS_SEVII_DUNGEON
	end

FiveIsland_WaterLabyrinth_EventScript_EggGentleman::
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	lock
	faceplayer
	goto_if_set FLAG_GOT_TOGEPI_EGG, FiveIsland_WaterLabyrinth_EventScript_PostEggComment
	goto_if_set FLAG_NO_ROOM_FOR_TOGEPI_EGG, FiveIsland_WaterLabyrinth_EventScript_ReturnForEgg
	msgbox FiveIsland_WaterLabyrinth_Text_LetMeTakeLookAtMons
	specialvar VAR_RESULT, GetLeadMonFriendship
	goto_if_eq VAR_RESULT, 6, FiveIsland_WaterLabyrinth_EventScript_LeadMonMaxFriendship
	msgbox FiveIsland_WaterLabyrinth_Text_HmmISeeIsee
	release
	end

FiveIsland_WaterLabyrinth_EventScript_MonDaisyComment::
	famechecker FAMECHECKER_DAISY, 2
	msgbox FiveIsland_WaterLabyrinth_Text_CuteMonRemindsMeOfDaisy
	release
	end

FiveIsland_WaterLabyrinth_EventScript_LeadMonMaxFriendship::
	msgbox FiveIsland_WaterLabyrinth_Text_TreatMonRightHaveThis
	goto FiveIsland_WaterLabyrinth_EventScript_TryGiveEgg
	end

FiveIsland_WaterLabyrinth_EventScript_TryGiveEgg::
	getpartysize
	goto_if_eq VAR_RESULT, PARTY_SIZE, FiveIsland_WaterLabyrinth_EventScript_NoRoomForEgg
	setflag FLAG_GOT_TOGEPI_EGG
	giveegg SPECIES_TOGEPI
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_LEVEL_UP
	message FiveIsland_WaterLabyrinth_Text_ReceivedEggFromMan
	waitfanfare
	waitmessage
	call EventScript_RestorePrevTextColor
	goto FiveIsland_WaterLabyrinth_EventScript_PostEggComment
	end

@ If the player has a Togepi/Togetic from this game (assumed to be the one the man gave you) then comment on it
@ Otherwise make normal comment
FiveIsland_WaterLabyrinth_EventScript_PostEggComment::
	bufferspeciesname STR_VAR_2, SPECIES_TOGEPI
	setvar VAR_0x8004, SPECIES_TOGEPI
	specialvar VAR_RESULT, PlayerPartyContainsSpeciesWithPlayerID
	goto_if_eq VAR_RESULT, TRUE, FiveIsland_WaterLabyrinth_EventScript_MonDaisyComment
	bufferspeciesname STR_VAR_2, SPECIES_TOGETIC
	setvar VAR_0x8004, SPECIES_TOGETIC
	specialvar VAR_RESULT, PlayerPartyContainsSpeciesWithPlayerID
	goto_if_eq VAR_RESULT, TRUE, FiveIsland_WaterLabyrinth_EventScript_MonDaisyComment
	msgbox FiveIsland_WaterLabyrinth_Text_GladIMetSomeoneLikeYou
	release
	end

FiveIsland_WaterLabyrinth_EventScript_NoRoomForEgg::
	setflag FLAG_NO_ROOM_FOR_TOGEPI_EGG
	msgbox FiveIsland_WaterLabyrinth_Text_DontHaveSpaceInYourParty
	release
	end

FiveIsland_WaterLabyrinth_EventScript_ReturnForEgg::
	goto FiveIsland_WaterLabyrinth_EventScript_TryGiveEgg
	end

FiveIsland_WaterLabyrinth_EventScript_KyogreTrigger::
	setvar VAR_TEMP_0, 1
	goto_if_ne VAR_KYOGRE_LOCATION, 1,  EventScript_End
	goto_if_set FLAG_KYOGRE_FLED, EventScript_End
	goto_if_set FLAG_CAUGHT_KYOGRE, EventScript_End
	lock
	applymovement LOCAL_ID_KYOGRE_LABYRINTH, FiveIsland_WaterLabyrinth_Movement_KyogreApproach
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 0  @ horizontal pan
	setvar VAR_0x8006, 3  @ num shakes
	setvar VAR_0x8007, 25  @ shake delay
	special ShakeScreen
	playse SE_PUDDLE
	delay 25
	playse SE_PUDDLE
	delay 25
	playse SE_PUDDLE
	delay 25
	waitmovement 0
	delay 20
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
	setvar VAR_0x8004, 3  @ vertical pan
	setvar VAR_0x8005, 0  @ horizontal pan
	setvar VAR_0x8006, 6  @ num shakes
	setvar VAR_0x8007, 2  @ shake delay
	special ShakeScreen
	waitmoncry
	delay 20
	seteventmon SPECIES_KYOGRE, 70
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	special StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, FiveIsland_WaterLabyrinth_EventScript_DefeatedKyogre
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, FiveIsland_WaterLabyrinth_EventScript_DefeatedKyogre
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, FiveIsland_WaterLabyrinth_EventScript_DefeatedKyogre
	setflag FLAG_CAUGHT_KYOGRE
	setflag FLAG_HIDE_KYOGRE
    fadescreen FADE_TO_BLACK
    removeobject LOCAL_ID_KYOGRE_LABYRINTH
    fadescreen FADE_FROM_BLACK
	setweather WEATHER_SUNNY
	doweather
	fadenewbgm MUS_SEVII_ROUTE
	savebgm MUS_SEVII_ROUTE
	release
	end

FiveIsland_WaterLabyrinth_EventScript_DefeatedKyogre::
	setflag FLAG_KYOGRE_FLED
	setflag FLAG_HIDE_KYOGRE
    fadescreen FADE_TO_BLACK
    removeobject LOCAL_ID_KYOGRE_LABYRINTH
    fadescreen FADE_FROM_BLACK
	setvar VAR_0x8004, SPECIES_KYOGRE
    bufferspeciesname STR_VAR_1, VAR_0x8004
    msgbox Text_MonFlewAway, MSGBOX_AUTOCLOSE
	setweather WEATHER_SUNNY
	doweather
	fadenewbgm MUS_SEVII_ROUTE
	savebgm MUS_SEVII_ROUTE
    release
    end

FiveIsland_WaterLabyrinth_Movement_KyogreApproach:
	walk_slower_right
	walk_slower_right
	walk_slower_right
	step_end
