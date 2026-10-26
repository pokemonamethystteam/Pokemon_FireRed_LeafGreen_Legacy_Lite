SixIsland_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SixIsland_OnTransition
	.byte 0

SixIsland_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_SIX_ISLAND
	end

SixIsland_EventScript_Hiker::
	msgbox SixIsland_Text_ThatWayToWaterPathRuinValley, MSGBOX_NPC
	end

SixIsland_EventScript_Boy::
	msgbox SixIsland_Text_SkyAtNightIsFantastic, MSGBOX_NPC
	end

SixIsland_EventScript_IslandSign::
	msgbox SixIsland_Text_IslandSign, MSGBOX_SIGN
	end

SixIsland_EventScript_CastformGuy::
	lock
	faceplayer
	goto_if_set FLAG_GREEN_PATH_CASTFORM, SixIsland_EventScript_CastformPostGift
	msgbox SixIsland_Text_WeatherInstitute
	waitmessage
	setvar VAR_TEMP_1, SPECIES_CASTFORM
	givemon SPECIES_CASTFORM, 30
	goto_if_eq VAR_RESULT, 0, SixIsland_EventScript_GetCastformParty
	goto_if_eq VAR_RESULT, 1, SixIsland_EventScript_GetCastformPC
	goto_if_eq VAR_RESULT, 2, EventScript_NoMoreRoomForPokemon
SixIsland_EventScript_CastformPostGift::
	msgbox SixIsland_Text_RecentlyDeveloped
	release
	end

SixIsland_EventScript_GetCastformParty::
	playfanfare MUS_LEVEL_UP
	message SixIsland_Text_ObtainedAnCastform
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_CASTFORM
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SixIsland_EventScript_SetGotCastform
	call EventScript_GetGiftMonPartySlot
	call EventScript_ChangePokemonNickname
	goto SixIsland_EventScript_SetGotCastform
	end

SixIsland_EventScript_GetCastformPC::
	playfanfare MUS_LEVEL_UP
	message SixIsland_Text_ObtainedAnCastform
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_CASTFORM
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SixIsland_EventScript_TransferCastformToPC
	call EventScript_NameReceivedBoxMon
	goto SixIsland_EventScript_TransferCastformToPC
	end

SixIsland_EventScript_TransferCastformToPC::
	call EventScript_TransferredToPC
	goto SixIsland_EventScript_SetGotCastform
	end

SixIsland_EventScript_SetGotCastform::
	msgbox SixIsland_Text_RecentlyDeveloped
	setflag FLAG_GREEN_PATH_CASTFORM
	release
	end
