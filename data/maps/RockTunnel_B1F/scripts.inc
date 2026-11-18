RockTunnel_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, RockTunnel_B1F_OnLoad
	.byte 0

RockTunnel_B1F_OnLoad::
	goto_if_set FLAG_OPEN_REGI_CAVES, RockTunnel_B1F_EventScript_OpenRegiPath
	goto_if_unset FLAG_CAUGHT_REGICE, RockTunnel_B1F_EventScript_TestResetRegice
	end

RockTunnel_B1F_EventScript_OpenRegiPath::
	setmetatile 16, 35, METATILE_RockTunnel_WallCornerLeft, 1
	setmetatile 16, 36, METATILE_RockTunnel_DirtGround, 0
	setmetatile 16, 37, METATILE_RockTunnel_DirtGround, 0
	setmetatile 16, 38, METATILE_RockTunnel_WallTopCornerLeft, 1
	setmetatile 15, 35, METATILE_RockTunnel_WallBottom, 1
	setmetatile 15, 36, METATILE_RockTunnel_DirtGround, 0
	setmetatile 15, 37, METATILE_RockTunnel_DirtGround, 0
	setmetatile 15, 38, METATILE_RockTunnel_WallTop, 1
	setmetatile 14, 35, METATILE_RockTunnel_WallBottom, 1
	setmetatile 14, 36, METATILE_RockTunnel_DirtGround, 0
	setmetatile 14, 37, METATILE_RockTunnel_DirtGround, 0
	setmetatile 14, 38, METATILE_RockTunnel_WallTop, 1
	setmetatile 13, 35, METATILE_RockTunnel_WallBottom, 1
	setmetatile 13, 36, METATILE_RockTunnel_DirtGround, 0
	setmetatile 13, 37, METATILE_RockTunnel_DirtGround, 0
	setmetatile 13, 38, METATILE_RockTunnel_WallTop, 1
	setmetatile 12, 35, METATILE_RockTunnel_WallBottom, 1
	setmetatile 12, 36, METATILE_RockTunnel_DirtGround, 0
	setmetatile 12, 37, METATILE_RockTunnel_DirtGround, 0
	setmetatile 12, 38, METATILE_RockTunnel_WallTop, 1
	setmetatile 11, 35, METATILE_RockTunnel_WallBottom, 1
	setmetatile 11, 36, METATILE_RockTunnel_DirtGround, 0
	setmetatile 11, 37, METATILE_RockTunnel_DirtGround, 0
	setmetatile 11, 38, METATILE_RockTunnel_WallTop, 1
	setmetatile 10, 35, METATILE_RockTunnel_WallBottom, 1
	setmetatile 10, 36, METATILE_RockTunnel_DirtGround, 0
	setmetatile 10, 37, METATILE_RockTunnel_DirtGround, 0
	setmetatile 10, 38, METATILE_RockTunnel_WallTop, 1
	return

RockTunnel_B1F_EventScript_Sofia::
	trainerbattle_single TRAINER_PICNICKER_SOFIA, RockTunnel_B1F_Text_SofiaIntro, RockTunnel_B1F_Text_SofiaDefeat
	msgbox RockTunnel_B1F_Text_SofiaPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_EventScript_Martha::
	trainerbattle_single TRAINER_PICNICKER_MARTHA, RockTunnel_B1F_Text_MarthaIntro, RockTunnel_B1F_Text_MarthaDefeat
	msgbox RockTunnel_B1F_Text_MarthaPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_EventScript_Dudley::
	trainerbattle_single TRAINER_HIKER_DUDLEY, RockTunnel_B1F_Text_DudleyIntro, RockTunnel_B1F_Text_DudleyDefeat
	msgbox RockTunnel_B1F_Text_DudleyPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_EventScript_Allen::
	trainerbattle_single TRAINER_HIKER_ALLEN, RockTunnel_B1F_Text_AllenIntro, RockTunnel_B1F_Text_AllenDefeat
	msgbox RockTunnel_B1F_Text_AllenPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_EventScript_Eric::
	trainerbattle_single TRAINER_HIKER_ERIC, RockTunnel_B1F_Text_EricIntro, RockTunnel_B1F_Text_EricDefeat
	msgbox RockTunnel_B1F_Text_EricPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_EventScript_Cooper::
	trainerbattle_single TRAINER_POKEMANIAC_COOPER, RockTunnel_B1F_Text_CooperIntro, RockTunnel_B1F_Text_CooperDefeat
	msgbox RockTunnel_B1F_Text_CooperPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_EventScript_Steve::
	trainerbattle_single TRAINER_POKEMANIAC_STEVE, RockTunnel_B1F_Text_SteveIntro, RockTunnel_B1F_Text_SteveDefeat
	msgbox RockTunnel_B1F_Text_StevePostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_EventScript_Winston::
	trainerbattle_single TRAINER_POKEMANIAC_WINSTON, RockTunnel_B1F_Text_WinstonIntro, RockTunnel_B1F_Text_WinstonDefeat
	msgbox RockTunnel_B1F_Text_WinstonPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_EventScript_TestResetRegice::
	goto_if_unset FLAG_REGICE_FLED, RockTunnel_B1F_EventScript_ResetRegice
	end

RockTunnel_B1F_EventScript_ResetRegice::
	clearflag FLAG_HIDE_REGICE
	end

RockTunnel_B1F_EventScript_Regice::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_REGICE, CRY_MODE_ENCOUNTER
	delay 40
	seteventmon SPECIES_REGICE, 40
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	special StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, RockTunnel_B1F_EventScript_DefeatedRegice
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, RockTunnel_B1F_EventScript_RanFromRegice
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, RockTunnel_B1F_EventScript_RanFromRegice
	setflag FLAG_CAUGHT_REGICE
	setflag FLAG_HIDE_REGICE
    fadescreen FADE_TO_BLACK
    removeobject LOCALID_REGICE
    fadescreen FADE_FROM_BLACK
	release
	end

RockTunnel_B1F_EventScript_DefeatedRegice::
	setflag FLAG_REGICE_FLED
	setvar VAR_0x8004, SPECIES_REGICE
	goto RockTunnel_B1F_EventScript_MonFlewAway
	end

RockTunnel_B1F_EventScript_RanFromRegice::
	setflag FLAG_REGICE_FLED
	setvar VAR_0x8004, SPECIES_REGICE
	goto RockTunnel_B1F_EventScript_MonFlewAway
	release
	end

RockTunnel_B1F_EventScript_MonFlewAway::
	setflag FLAG_HIDE_REGICE
    fadescreen FADE_TO_BLACK
    removeobject LOCALID_REGICE
    fadescreen FADE_FROM_BLACK
    bufferspeciesname STR_VAR_1, VAR_0x8004
    msgbox Text_MonFlewAway, MSGBOX_AUTOCLOSE
    release
    end
