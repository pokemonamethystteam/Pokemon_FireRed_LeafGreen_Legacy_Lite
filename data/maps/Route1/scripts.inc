Route1_MapScripts::
	.byte 0

Route1_EventScript_MartClerk::
	lock
	faceplayer
	goto_if_set FLAG_GOT_POTION_ON_ROUTE_1, Route1_EventScript_AlreadyGotPotion
	msgbox Route1_Text_WorkAtPokeMartTakeSample
	textcolor NPC_TEXT_COLOR_NEUTRAL
	checkitemspace ITEM_POTION
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
	bufferitemname STR_VAR_2, ITEM_POTION
	playfanfare MUS_LEVEL_UP
	message Text_ObtainedTheX
	waitmessage
	waitfanfare
	additem ITEM_POTION
	msgbox Route1_Text_PutPotionAway
	call EventScript_RestorePrevTextColor
	setflag FLAG_GOT_POTION_ON_ROUTE_1
	release
	end

Route1_EventScript_ProfOak::
	lock
	faceplayer
	goto_if_set FLAG_ROUTE1_PROF_OAK_DEFEATED, Route1_EventScript_ProfOakDefeated
	msgbox Route1_Text_ProfOakIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route1_EventScript_ProfOakDeclined
	msgbox Route1_Text_ProfOakAccepted
	trainerbattle_no_intro TRAINER_PROF_OAK, Route1_Text_ProfOakDefeat
	msgbox Route1_Text_DefeatedProfOak
	setflag FLAG_ROUTE1_PROF_OAK_DEFEATED
	clearflag FLAG_HIDE_OAK_IN_HIS_LAB
	closemessage
	release
	end

Route1_EventScript_ProfOakDeclined::
	msgbox Route1_Text_ProfOakDeclined
	closemessage
	release
	end

Route1_EventScript_ProfOakDefeated::
	msgbox Route1_Text_DefeatedProfOak
	closemessage
	release
	end

Route1_EventScript_AlreadyGotPotion::
	msgbox Route1_Text_ComeSeeUsIfYouNeedPokeBalls
	release
	end

Route1_EventScript_Boy::
	msgbox Route1_Text_CanJumpFromLedges, MSGBOX_NPC
	end

Route1_EventScript_RouteSign::
	msgbox Route1_Text_RouteSign, MSGBOX_SIGN
	end
