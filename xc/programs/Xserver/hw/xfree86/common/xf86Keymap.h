/* $XFree86: xc/programs/Xserver/hw/xfree86/common/xf86Keymap.h,v 3.8 1996/02/04 09:06:20 dawes Exp $ */
/*
 *
 * For Scancodes see notes in atKeynames.h  !!!!
 *
 */
/* $XConsortium: xf86Keymap.h /main/13 1996/01/31 10:06:32 kaleb $ */

static KeySym map[NUM_KEYCODES * GLYPHS_PER_KEY] = { 
#ifndef PC98
    /* 0x00 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x01 */  XK_Escape,      NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x02 */  XK_1,           XK_exclam,	NoSymbol,	NoSymbol,
    /* 0x03 */  XK_2,           XK_at,		NoSymbol,	NoSymbol,
    /* 0x04 */  XK_3,           XK_numbersign,	NoSymbol,	NoSymbol,
    /* 0x05 */  XK_4,           XK_dollar,	NoSymbol,	NoSymbol,
    /* 0x06 */  XK_5,           XK_percent,	NoSymbol,	NoSymbol,
    /* 0x07 */  XK_6,           XK_asciicircum,	NoSymbol,	NoSymbol,
    /* 0x08 */  XK_7,           XK_ampersand,	NoSymbol,	NoSymbol,
    /* 0x09 */  XK_8,           XK_asterisk,	NoSymbol,	NoSymbol,
    /* 0x0a */  XK_9,           XK_parenleft,	NoSymbol,	NoSymbol,
    /* 0x0b */  XK_0,           XK_parenright,	NoSymbol,	NoSymbol,
    /* 0x0c */  XK_minus,       XK_underscore,	NoSymbol,	NoSymbol,
    /* 0x0d */  XK_equal,       XK_plus,	NoSymbol,	NoSymbol,
    /* 0x0e */  XK_BackSpace,   NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x0f */  XK_Tab,         NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x10 */  XK_Q,           NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x11 */  XK_W,           NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x12 */  XK_E,           NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x13 */  XK_R,           NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x14 */  XK_T,           NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x15 */  XK_Y,           NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x16 */  XK_U,           NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x17 */  XK_I,           NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x18 */  XK_O,           NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x19 */  XK_P,           NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x1a */  XK_bracketleft, XK_braceleft,	NoSymbol,	NoSymbol,
    /* 0x1b */  XK_bracketright,XK_braceright,	NoSymbol,	NoSymbol,
    /* 0x1c */  XK_Return,      NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x1d */  XK_Control_L,   NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x1e */  XK_A,           NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x1f */  XK_S,           NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x20 */  XK_D,           NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x21 */  XK_F,           NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x22 */  XK_G,           NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x23 */  XK_H,           NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x24 */  XK_J,           NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x25 */  XK_K,           NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x26 */  XK_L,           NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x27 */  XK_semicolon,   XK_colon,	NoSymbol,	NoSymbol,
    /* 0x28 */  XK_quoteright,  XK_quotedbl,	NoSymbol,	NoSymbol,
    /* 0x29 */  XK_quoteleft,	XK_asciitilde,	NoSymbol,	NoSymbol,
    /* 0x2a */  XK_Shift_L,     NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x2b */  XK_backslash,   XK_bar,		NoSymbol,	NoSymbol,
    /* 0x2c */  XK_Z,           NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x2d */  XK_X,           NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x2e */  XK_C,           NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x2f */  XK_V,           NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x30 */  XK_B,           NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x31 */  XK_N,           NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x32 */  XK_M,           NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x33 */  XK_comma,       XK_less,	NoSymbol,	NoSymbol,
    /* 0x34 */  XK_period,      XK_greater,	NoSymbol,	NoSymbol,
    /* 0x35 */  XK_slash,       XK_question,	NoSymbol,	NoSymbol,
    /* 0x36 */  XK_Shift_R,     NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x37 */  XK_KP_Multiply, NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x38 */  XK_Alt_L,	XK_Meta_L,	NoSymbol,	NoSymbol,
    /* 0x39 */  XK_space,       NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x3a */  XK_Caps_Lock,   NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x3b */  XK_F1,          NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x3c */  XK_F2,          NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x3d */  XK_F3,          NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x3e */  XK_F4,          NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x3f */  XK_F5,          NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x40 */  XK_F6,          NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x41 */  XK_F7,          NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x42 */  XK_F8,          NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x43 */  XK_F9,          NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x44 */  XK_F10,         NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x45 */  XK_Num_Lock,    NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x46 */  XK_Scroll_Lock,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x47 */  XK_KP_Home,	XK_KP_7,	NoSymbol,	NoSymbol,
    /* 0x48 */  XK_KP_Up,	XK_KP_8,	NoSymbol,	NoSymbol,
    /* 0x49 */  XK_KP_Prior,	XK_KP_9,	NoSymbol,	NoSymbol,
    /* 0x4a */  XK_KP_Subtract, NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x4b */  XK_KP_Left,	XK_KP_4,	NoSymbol,	NoSymbol,
    /* 0x4c */  NoSymbol,	XK_KP_5,	NoSymbol,	NoSymbol,
    /* 0x4d */  XK_KP_Right,	XK_KP_6,	NoSymbol,	NoSymbol,
    /* 0x4e */  XK_KP_Add,      NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x4f */  XK_KP_End,	XK_KP_1,	NoSymbol,	NoSymbol,
    /* 0x50 */  XK_KP_Down,	XK_KP_2,	NoSymbol,	NoSymbol,
    /* 0x51 */  XK_KP_Next,	XK_KP_3,	NoSymbol,	NoSymbol,
    /* 0x52 */  XK_KP_Insert,	XK_KP_0,	NoSymbol,	NoSymbol,
    /* 0x53 */  XK_KP_Delete,	XK_KP_Decimal,	NoSymbol,	NoSymbol,
    /* 0x54 */  XK_Sys_Req,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x55 */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x56 */  XK_less,	XK_greater,	NoSymbol,	NoSymbol,
    /* 0x57 */  XK_F11,		NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x58 */  XK_F12,		NoSymbol,	NoSymbol,	NoSymbol,

    /* 0x59 */  XK_Home,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x5a */  XK_Up,		NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x5b */  XK_Prior,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x5c */  XK_Left,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x5d */  XK_Begin,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x5e */  XK_Right,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x5f */  XK_End,		NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x60 */  XK_Down,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x61 */  XK_Next,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x62 */  XK_Insert,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x63 */  XK_Delete,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x64 */  XK_KP_Enter,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x65 */  XK_Control_R,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x66 */  XK_Pause,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x67 */  XK_Print,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x68 */  XK_KP_Divide,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x69 */  XK_Alt_R,	XK_Meta_R,	NoSymbol,	NoSymbol,
    /* 0x6a */  XK_Break,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x6b */  XK_Meta_L,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x6c */  XK_Meta_R,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x6d */  XK_Menu,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x6e */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x6f */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x70 */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x71 */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x72 */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x73 */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x74 */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x75 */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x76 */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x77 */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x78 */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x79 */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x7a */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x7b */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x7c */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x7d */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x7e */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
#else /* PC98 */
    /* 0x00 */  XK_Escape,      NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x01 */  XK_1,      	XK_exclam,	XK_kana_NU,	NoSymbol,
    /* 0x02 */  XK_2,           XK_quotedbl,	XK_kana_FU,	NoSymbol,
    /* 0x03 */  XK_3,           XK_numbersign,	XK_kana_A,	XK_kana_a,
    /* 0x04 */  XK_4,           XK_dollar,	XK_kana_U,	XK_kana_u,
    /* 0x05 */  XK_5,           XK_percent,	XK_kana_E,	XK_kana_e,
    /* 0x06 */  XK_6,           XK_ampersand,	XK_kana_O,	XK_kana_o,
    /* 0x07 */  XK_7,           XK_quoteright,	XK_kana_YA,	XK_kana_ya,
    /* 0x08 */  XK_8,           XK_parenleft,	XK_kana_YU,	XK_kana_yu,
    /* 0x09 */  XK_9,           XK_parenright,	XK_kana_YO,	XK_kana_yo,
    /* 0x0a */  XK_0,           NoSymbol,	XK_kana_WA,	XK_kana_WO,
    /* 0x0b */  XK_minus,       XK_equal,	XK_kana_HO,	NoSymbol,
    /* 0x0c */  XK_asciicircum, XK_quoteleft,	XK_kana_HE,	NoSymbol,
    /* 0x0d */  XK_backslash,   XK_bar,		XK_prolongedsound,	NoSymbol,
    /* 0x0e */  XK_BackSpace,   NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x0f */  XK_Tab,         NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x10 */  XK_Q,           NoSymbol,	XK_kana_TA,	NoSymbol,
    /* 0x11 */  XK_W,           NoSymbol,	XK_kana_TE,	NoSymbol,
    /* 0x12 */  XK_E,           NoSymbol,	XK_kana_I,	XK_kana_i,
    /* 0x13 */  XK_R,           NoSymbol,	XK_kana_SU,	NoSymbol,
    /* 0x14 */  XK_T,           NoSymbol,	XK_kana_KA,	NoSymbol,
    /* 0x15 */  XK_Y,           NoSymbol,	XK_kana_N,	NoSymbol,
    /* 0x16 */  XK_U,           NoSymbol,	XK_kana_NA,	NoSymbol,
    /* 0x17 */  XK_I,           NoSymbol,	XK_kana_NI,	NoSymbol,
    /* 0x18 */  XK_O,           NoSymbol,	XK_kana_RA,	NoSymbol,
    /* 0x19 */  XK_P,           NoSymbol,	XK_kana_SE,	NoSymbol,
    /* 0x1a */  XK_at,          XK_asciitilde,	XK_voicedsound,	NoSymbol,
    /* 0x1b */  XK_bracketleft, XK_braceleft,	XK_semivoicedsound,	XK_kana_openingbracket,
    /* 0x1c */  XK_Return,      NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x1d */  XK_A,		NoSymbol,	XK_kana_CHI,	NoSymbol,
    /* 0x1e */  XK_S,   	NoSymbol,	XK_kana_TO,	NoSymbol,
    /* 0x1f */  XK_D,           NoSymbol,	XK_kana_SHI,	NoSymbol,
    /* 0x20 */  XK_F,           NoSymbol,	XK_kana_HA,	NoSymbol,
    /* 0x21 */  XK_G,           NoSymbol,	XK_kana_KI,	NoSymbol,
    /* 0x22 */  XK_H,           NoSymbol,	XK_kana_KU,	NoSymbol,
    /* 0x23 */  XK_J,           NoSymbol,	XK_kana_MA,	NoSymbol,
    /* 0x24 */  XK_K,           NoSymbol,	XK_kana_NO,	NoSymbol,
    /* 0x25 */  XK_L,           NoSymbol,	XK_kana_RI,	NoSymbol,
    /* 0x26 */  XK_semicolon,   XK_plus,	XK_kana_RE,	NoSymbol,
    /* 0x27 */  XK_colon,	XK_asterisk,	XK_kana_KE,	NoSymbol,
    /* 0x28 */  XK_bracketright,XK_braceright,	XK_kana_MU,	XK_kana_closingbracket,
    /* 0x29 */  XK_Z,		NoSymbol,	XK_kana_TSU,	NoSymbol,
    /* 0x2a */  XK_X,		NoSymbol,	XK_kana_SA,	NoSymbol,
    /* 0x2b */  XK_C,		NoSymbol,	XK_kana_SO,	NoSymbol,
    /* 0x2c */  XK_V,           NoSymbol,	XK_kana_HI,	NoSymbol,
    /* 0x2d */  XK_B,           NoSymbol,	XK_kana_KO,	NoSymbol,
    /* 0x2e */  XK_N,           NoSymbol,	XK_kana_MI,	NoSymbol,
    /* 0x2f */  XK_M,           NoSymbol,	XK_kana_MO,	NoSymbol,
    /* 0x30 */  XK_comma,       XK_less,	XK_kana_NE,	XK_kana_comma,
    /* 0x31 */  XK_period,      XK_greater,	XK_kana_RU,	XK_kana_fullstop,
    /* 0x32 */  XK_slash,       XK_question,	XK_kana_ME,	XK_kana_middledot,
    /* 0x33 */  XK_underscore,	XK_underscore,	XK_kana_RO,	NoSymbol,
    /* 0x34 */  XK_space,       NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x35 */  XK_Henkan,	XK_Kanji,	NoSymbol,	NoSymbol,
    /* 0x36 */  XK_Next,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x37 */  XK_Prior,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x38 */  XK_Insert,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x39 */  XK_Delete,      NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x3a */  XK_Up,		NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x3b */  XK_Left,        NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x3c */  XK_Right,       NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x3d */  XK_Down,        NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x3e */  XK_Clear,       XK_Home,	NoSymbol,	NoSymbol,
    /* 0x3f */  XK_Help,        NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x40 */  XK_KP_Subtract,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x41 */  XK_KP_Divide,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x42 */  XK_KP_7,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x43 */  XK_KP_8,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x44 */  XK_KP_9,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x45 */  XK_KP_Multiply,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x46 */  XK_KP_4,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x47 */  XK_KP_5,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x48 */  XK_KP_6,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x49 */  XK_KP_Add,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x4a */  XK_KP_1,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x4b */  XK_KP_2,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x4c */  XK_KP_3,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x4d */  XK_KP_Equal,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x4e */  XK_KP_0,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x4f */  XK_KP_Separator,NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x50 */  XK_KP_Decimal,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x51 */  XK_Muhenkan,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x52 */  XK_F11,		NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x53 */  XK_F12,		NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x54 */  XK_F13,		NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x55 */  XK_F14,		NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x56 */  XK_F15,		NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x57 */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x58 */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x59 */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x5a */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x5b */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x5c */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x5d */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x5e */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x5f */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x60 */  XK_Break,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x61 */  XK_Print,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x62 */  XK_F1,		NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x63 */  XK_F2,		NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x64 */  XK_F3,		NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x65 */  XK_F4,		NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x66 */  XK_F5,		NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x67 */  XK_F6,		NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x68 */  XK_F7,		NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x69 */  XK_F8,		NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x6a */  XK_F9,		NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x6b */ 	XK_F10,		NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x6c */ 	NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x6d */ 	NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x6e */ 	NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x6f */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x70 */ 	XK_Shift_L,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x71 */ 	XK_Caps_Lock,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x72 */  XK_kana_switch,	NoSymbol,	XK_kana_switch,	NoSymbol,
    /* 0x73 */ 	XK_Alt_L,	XK_Meta_L,	NoSymbol,	NoSymbol,
    /* 0x74 */ 	XK_Control_L,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x75 */ 	NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x76 */ 	NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x77 */ 	NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x78 */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x79 */ 	NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x7a */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x7b */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x7c */ 	NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x7d */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x7e */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
#endif /* PC98 */
    /* 0x7f */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,

    /* These are for ServerNumLock handling */
    /* 0x80 */  XK_KP_7,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x81 */  XK_KP_8,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x82 */  XK_KP_9,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x83 */  XK_KP_4,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x84 */  XK_KP_5,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x85 */  XK_KP_6,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x86 */  XK_KP_1,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x87 */  XK_KP_2,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x88 */  XK_KP_3,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x89 */  XK_KP_0,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x8a */  XK_KP_Decimal,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x8b */  XK_Home,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x8c */  XK_Up,		NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x8d */  XK_Prior,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x8e */  XK_Left,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x8f */  XK_Begin,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x90 */  XK_Right,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x91 */  XK_End,		NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x92 */  XK_Down,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x93 */  XK_Next,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x94 */  XK_Insert,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x95 */  XK_Delete,	NoSymbol,	NoSymbol,	NoSymbol,
};

static KeySym map84[NUM_KEYCODES * GLYPHS_PER_KEY] = { 
    /* 0x00 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x01 */  XK_Escape,      NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x02 */  XK_1,           XK_exclam,	NoSymbol,	NoSymbol,
    /* 0x03 */  XK_2,           XK_at,		NoSymbol,	NoSymbol,
    /* 0x04 */  XK_3,           XK_numbersign,	NoSymbol,	NoSymbol,
    /* 0x05 */  XK_4,           XK_dollar,	NoSymbol,	NoSymbol,
    /* 0x06 */  XK_5,           XK_percent,	NoSymbol,	NoSymbol,
    /* 0x07 */  XK_6,           XK_asciicircum,	NoSymbol,	NoSymbol,
    /* 0x08 */  XK_7,           XK_ampersand,	NoSymbol,	NoSymbol,
    /* 0x09 */  XK_8,           XK_asterisk,	NoSymbol,	NoSymbol,
    /* 0x0a */  XK_9,           XK_parenleft,	NoSymbol,	NoSymbol,
    /* 0x0b */  XK_0,           XK_parenright,	NoSymbol,	NoSymbol,
    /* 0x0c */  XK_minus,       XK_underscore,	NoSymbol,	NoSymbol,
    /* 0x0d */  XK_equal,       XK_plus,	NoSymbol,	NoSymbol,
    /* 0x0e */  XK_BackSpace,   NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x0f */  XK_Tab,         NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x10 */  XK_Q,           NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x11 */  XK_W,           NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x12 */  XK_E,           NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x13 */  XK_R,           NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x14 */  XK_T,           NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x15 */  XK_Y,           NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x16 */  XK_U,           NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x17 */  XK_I,           NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x18 */  XK_O,           NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x19 */  XK_P,           NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x1a */  XK_bracketleft, XK_braceleft,	NoSymbol,	NoSymbol,
    /* 0x1b */  XK_bracketright,XK_braceright,	NoSymbol,	NoSymbol,
    /* 0x1c */  XK_Return,      NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x1d */  XK_Control_L,   NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x1e */  XK_A,           NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x1f */  XK_S,           NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x20 */  XK_D,           NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x21 */  XK_F,           NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x22 */  XK_G,           NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x23 */  XK_H,           NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x24 */  XK_J,           NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x25 */  XK_K,           NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x26 */  XK_L,           NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x27 */  XK_semicolon,   XK_colon,	NoSymbol,	NoSymbol,
    /* 0x28 */  XK_quoteright,  XK_quotedbl,	NoSymbol,	NoSymbol,
    /* 0x29 */  XK_quoteleft,	XK_asciitilde,	NoSymbol,	NoSymbol,
    /* 0x2a */  XK_Shift_L,     NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x2b */  XK_backslash,   XK_bar,		NoSymbol,	NoSymbol,
    /* 0x2c */  XK_Z,           NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x2d */  XK_X,           NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x2e */  XK_C,           NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x2f */  XK_V,           NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x30 */  XK_B,           NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x31 */  XK_N,           NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x32 */  XK_M,           NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x33 */  XK_comma,       XK_less,	NoSymbol,	NoSymbol,
    /* 0x34 */  XK_period,      XK_greater,	NoSymbol,	NoSymbol,
    /* 0x35 */  XK_slash,       XK_question,	NoSymbol,	NoSymbol,
    /* 0x36 */  XK_Shift_R,     NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x37 */  XK_KP_Multiply, NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x38 */  XK_Alt_L,	XK_Meta_L,	NoSymbol,	NoSymbol,
    /* 0x39 */  XK_space,       NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x3a */  XK_Caps_Lock,   NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x3b */  XK_F1,          NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x3c */  XK_F2,          NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x3d */  XK_F3,          NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x3e */  XK_F4,          NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x3f */  XK_F5,          NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x40 */  XK_F6,          NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x41 */  XK_F7,          NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x42 */  XK_F8,          NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x43 */  XK_F9,          NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x44 */  XK_F10,         NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x45 */  XK_Num_Lock,    NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x46 */  XK_Scroll_Lock,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x47 */  XK_KP_Home,	XK_KP_7,	NoSymbol,	NoSymbol,
    /* 0x48 */  XK_KP_Up,	XK_KP_8,	NoSymbol,	NoSymbol,
    /* 0x49 */  XK_KP_Prior,	XK_KP_9,	NoSymbol,	NoSymbol,
    /* 0x4a */  XK_KP_Subtract, NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x4b */  XK_KP_Left,	XK_KP_4,	NoSymbol,	NoSymbol,
    /* 0x4c */  NoSymbol,	XK_KP_5,	NoSymbol,	NoSymbol,
    /* 0x4d */  XK_KP_Right,	XK_KP_6,	NoSymbol,	NoSymbol,
    /* 0x4e */  XK_KP_Add,      NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x4f */  XK_KP_End,	XK_KP_1,	NoSymbol,	NoSymbol,
    /* 0x50 */  XK_KP_Down,	XK_KP_2,	NoSymbol,	NoSymbol,
    /* 0x51 */  XK_KP_Next,	XK_KP_3,	NoSymbol,	NoSymbol,
    /* 0x52 */  XK_KP_Insert,	XK_KP_0,	NoSymbol,	NoSymbol,
    /* 0x53 */  XK_KP_Delete,	XK_KP_Decimal,	NoSymbol,	NoSymbol,
    /* 0x54 */  XK_Sys_Req,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x55 */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x56 */  XK_less,	XK_greater,	NoSymbol,	NoSymbol,
    /* 0x57 */  XK_F11,		NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x58 */  XK_F12,		NoSymbol,	NoSymbol,	NoSymbol,

    /* 0x59 */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x5a */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x5b */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x5c */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x5d */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x5e */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x5f */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x60 */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x61 */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x62 */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x63 */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x64 */  XK_KP_Enter,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x65 */  XK_Control_R,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x66 */  XK_Pause,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x67 */  XK_Print,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x68 */  XK_KP_Divide,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x69 */  XK_Alt_R,	XK_Meta_R,	NoSymbol,	NoSymbol,
    /* 0x6a */  XK_Break,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x6b */  XK_Meta_L,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x6c */  XK_Meta_R,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x6d */  XK_Menu,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x6e */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x6f */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x70 */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x71 */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x72 */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x73 */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x74 */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x75 */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x76 */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x77 */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x78 */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x79 */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x7a */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x7b */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x7c */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x7d */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x7e */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x7f */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,

    /* These are for ServerNumLock handling */
    /* 0x80 */  XK_KP_7,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x81 */  XK_KP_8,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x82 */  XK_KP_9,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x83 */  XK_KP_4,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x84 */  XK_KP_5,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x85 */  XK_KP_6,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x86 */  XK_KP_1,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x87 */  XK_KP_2,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x88 */  XK_KP_3,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x89 */  XK_KP_0,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x8a */  XK_KP_Decimal,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x8b */  XK_Home,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x8c */  XK_Up,		NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x8d */  XK_Prior,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x8e */  XK_Left,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x8f */  XK_Begin,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x90 */  XK_Right,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x91 */  XK_End,		NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x92 */  XK_Down,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x93 */  XK_Next,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x94 */  XK_Insert,	NoSymbol,	NoSymbol,	NoSymbol,
    /* 0x95 */  XK_Delete,	NoSymbol,	NoSymbol,	NoSymbol,
};
