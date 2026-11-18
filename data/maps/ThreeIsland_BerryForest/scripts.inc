ThreeIsland_BerryForest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ThreeIsland_BerryForest_OnTransition
	.byte 0

ThreeIsland_BerryForest_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_THREE_ISLAND_BERRY_FOREST
	setescapewarp MAP_THREE_ISLAND_BOND_BRIDGE, 12, 6
	end

ThreeIsland_BerryForest_EventScript_Lostelle::
	lock
	faceplayer
	msgbox ThreeIsland_BerryForest_Text_HelpScaryPokemon
	playse SE_PIN
	applymovement LOCALID_BERRY_FOREST_LOSTELLE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_BERRY_FOREST_LOSTELLE, ThreeIsland_BerryForest_Movement_LostelleLookAround
	waitmovement 0
	msgbox ThreeIsland_BerryForest_Text_HereItComesAgain
	goto_if_questlog EventScript_ReleaseEnd
	waitse
	playmoncry SPECIES_HYPNO, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_HYPNO, 30
	dowildbattle
	special QuestLog_CutRecording
	applymovement LOCALID_BERRY_FOREST_LOSTELLE, Common_Movement_FacePlayer
	waitmovement 0
	msgbox ThreeIsland_BerryForest_Text_ThankYouHaveThis
	giveitem ITEM_IAPAPA_BERRY
	call_if_eq VAR_RESULT, FALSE, ThreeIsland_BerryForest_EventScript_NoRoomForBerry
	special BufferBigGuyOrBigGirlString
	msgbox ThreeIsland_BerryForest_Text_LetsGoHome
	closemessage
	setflag FLAG_RESCUED_LOSTELLE
	setflag FLAG_HIDE_LOSTELLE_IN_BERRY_FOREST
	setvar VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 2
	clearflag FLAG_HIDE_TWO_ISLAND_GAME_CORNER_LOSTELLE
	warp MAP_TWO_ISLAND_JOYFUL_GAME_CORNER, 6, 6
	waitstate
	release
	end

ThreeIsland_BerryForest_EventScript_NoRoomForBerry::
	msgbox ThreeIsland_BerryForest_Text_BerryPouchIsFull
	return

ThreeIsland_BerryForest_Movement_LostelleLookAround::
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_right
	delay_8
	walk_in_place_faster_left
	step_end

ThreeIsland_BerryForest_EventScript_WelcomeSign::
	msgbox ThreeIsland_BerryForest_Text_WelcomeToBerryForest, MSGBOX_SIGN
	end

ThreeIsland_BerryForest_EventScript_BewareSign::
	msgbox ThreeIsland_BerryForest_Text_BewareWildBerryLovingMons, MSGBOX_SIGN
	end

ThreeIsland_BerryForest_EventScript_Celebi::
	lock
	goto_if_set FLAG_CELEBI_FLED, ThreeIsland_BerryForest_EventScript_AnOldShrine
	goto_if_set FLAG_CAUGHT_CELEBI, ThreeIsland_BerryForest_EventScript_AnOldShrine
	msgbox ThreeIsland_BerryForest_Text_OldShrineFlute, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_ReleaseEnd
    message Text_PlayedPokeFlute
    waitmessage
	special Script_FadeOutMapMusic
    playfanfare MUS_POKE_FLUTE
	delay 80
	fadescreen FADE_TO_WHITE
    removeobject LOCALID_CELEBI
	setobjectxyperm LOCALID_CELEBI, 17, 3
	addobject LOCALID_CELEBI
	applymovement LOCALID_CELEBI, ThreeIsland_BerryForest_Movement_Levitate
	fadescreen FADE_FROM_WHITE
	delay 80
	fadescreen FADE_TO_WHITE
    removeobject LOCALID_CELEBI
	setobjectxyperm LOCALID_CELEBI, 12, 4
	addobject LOCALID_CELEBI
	fadescreen FADE_FROM_WHITE
	delay 80
	fadescreen FADE_TO_WHITE
    removeobject LOCALID_CELEBI
	setobjectxyperm LOCALID_CELEBI, 13, 5
	addobject LOCALID_CELEBI
	fadescreen FADE_FROM_WHITE
	delay 120
	playmoncry SPECIES_CELEBI, CRY_MODE_ENCOUNTER
	delay 40
	seteventmon SPECIES_CELEBI, 30
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	special StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, ThreeIsland_BerryForest_EventScript_DefeatedCelebi
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, ThreeIsland_BerryForest_EventScript_DefeatedCelebi
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, ThreeIsland_BerryForest_EventScript_DefeatedCelebi
	setflag FLAG_CAUGHT_CELEBI
	setflag FLAG_HIDE_CELEBI
    fadescreen FADE_TO_BLACK
    removeobject LOCALID_CELEBI
	setobjectxyperm LOCALID_CELEBI, 56, 46
    fadescreen FADE_FROM_BLACK
	release
	end

ThreeIsland_BerryForest_EventScript_AnOldShrine::
	msgbox ThreeIsland_BerryForest_Text_OldShrine
	release
	end

ThreeIsland_BerryForest_EventScript_DefeatedCelebi::
	setflag FLAG_CELEBI_FLED
	setvar VAR_0x8004, SPECIES_CELEBI
	goto ThreeIsland_BerryForest_EventScript_MonFlewAway
	end

ThreeIsland_BerryForest_EventScript_MonFlewAway::
	setflag FLAG_HIDE_CELEBI
    fadescreen FADE_TO_BLACK
    removeobject LOCALID_CELEBI
	setobjectxyperm LOCALID_CELEBI, 56, 46
    fadescreen FADE_FROM_BLACK
    bufferspeciesname STR_VAR_1, VAR_0x8004
    msgbox Text_MonFlewAway, MSGBOX_AUTOCLOSE
    release
    end

ThreeIsland_BerryForest_Movement_Levitate:
	levitate
	step_end
