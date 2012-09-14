#pragma once


enum MailCMD
{
	MAIL_RES_MAIL_SENT = 0,
	MAIL_RES_MONEY_TAKEN = 1,
	MAIL_RES_ITEM_TAKEN = 2,
	MAIL_RES_RETURNED_TO_SENDER = 3,
	MAIL_RES_DELETED = 4,
	MAIL_RES_MADE_PERMANENT = 5
};

enum MailFlags
{
	MAIL_FLAG_NO_COST_FOR_GM					= 1,
	MAIL_FLAG_CAN_SEND_TO_OPPOSITE_FACTION	  = 2,
	MAIL_FLAG_CAN_SEND_TO_OPPOSITE_FACTION_GM   = 4,
	MAIL_FLAG_DISABLE_POSTAGE_COSTS			 = 8,
	MAIL_FLAG_DISABLE_HOUR_DELAY_FOR_ITEMS	  = 16,
	MAIL_FLAG_NO_EXPIRY						 = 32,
};

enum MailTypes
{
	NORMAL,
	COD,
	AUCTION,
	SHOP,
};

enum MailError
{
	MAIL_OK = 0,
	MAIL_ERR_BAG_FULL = 1,
	MAIL_ERR_CANNOT_SEND_TO_SELF = 2,
	MAIL_ERR_NOT_ENOUGH_MONEY = 3,
	MAIL_ERR_RECIPIENT_NOT_FOUND = 4,
	MAIL_ERR_NOT_YOUR_ALLIANCE = 5,
	MAIL_ERR_INTERNAL_ERROR = 6,
	MAIL_MAILBOX_IS_FULL,
};

enum eShopCategory
{
	shopcategory_equip,
	shopcategory_cloths,
	shopcategory_ride,
	shopcategory_shapeshift,
	shopcategory_consume,
};

enum eShopSumCategory
{

};

enum eBuyType
{
	times_30days,
	times_60days,
	times_never,
};


