/*	$NetBSD: lk201Keymap.h,v 1.1 2001/09/18 20:02:52 ad Exp $	*/

/* Don't include this: it has bogue keycode values? */
/* #include	<dev/dec/lk201.h> */

#define LK201_GLYPHS_PER_KEY	4
#define LK201_NUM_KEYCODES	(251 - 86 + 1)

static KeySym
lk201map[LK201_NUM_KEYCODES * LK201_GLYPHS_PER_KEY] = {
    /*   -- */ /* NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol, */
    /*   86 */  XK_F1,          NoSymbol,	NoSymbol,	NoSymbol,
    /*   87 */  XK_F2,          NoSymbol,	NoSymbol,	NoSymbol,
    /*   88 */  XK_F3,          NoSymbol,	NoSymbol,	NoSymbol,
    /*   89 */  XK_F4,          NoSymbol,	NoSymbol,	NoSymbol,
    /*   90 */  XK_F5,          NoSymbol,	NoSymbol,	NoSymbol,
    /*   91 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*   92 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*   93 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*   94 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*   95 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*   96 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*   97 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*   98 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*   99 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*  100 */  XK_F6,          NoSymbol,	NoSymbol,	NoSymbol,
    /*  101 */  XK_F7,          NoSymbol,	NoSymbol,	NoSymbol,
    /*  102 */  XK_F8,          NoSymbol,	NoSymbol,	NoSymbol,
    /*  103 */  XK_F9,          NoSymbol,	NoSymbol,	NoSymbol,
    /*  104 */  XK_F10,         NoSymbol,	NoSymbol,	NoSymbol,
    /*  105 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*  106 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*  107 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*  108 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*  109 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*  110 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*  111 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*  112 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*  113 */  XK_F11,         NoSymbol,	NoSymbol,	NoSymbol,
    /*  114 */  XK_F12,         NoSymbol,	NoSymbol,	NoSymbol,
    /*  115 */  XK_F13,         NoSymbol,	NoSymbol,	NoSymbol,
    /*  116 */  XK_F14,         NoSymbol,	NoSymbol,	NoSymbol,
    /*  117 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*  118 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*  119 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*  120 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*  121 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*  122 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*  123 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*  124 */  XK_F15,         NoSymbol,	NoSymbol,	NoSymbol,
    /*  125 */  XK_F16,         NoSymbol,	NoSymbol,	NoSymbol,
    /*  126 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*  127 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*  128 */  XK_F17,         NoSymbol,	NoSymbol,	NoSymbol,
    /*  129 */  XK_F18,         NoSymbol,	NoSymbol,	NoSymbol,
    /*  130 */  XK_F19,         NoSymbol,	NoSymbol,	NoSymbol,
    /*  131 */  XK_F20,         NoSymbol,	NoSymbol,	NoSymbol,
    /*  132 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*  133 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*  134 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*  135 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*  136 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*  137 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*  138 */  XK_Insert,	NoSymbol,	NoSymbol,	NoSymbol,
    /*  139 */  XK_Home,	NoSymbol,	NoSymbol,	NoSymbol,
    /*  140 */  XK_Prior,	NoSymbol,	NoSymbol,	NoSymbol,
    /*  141 */  XK_Delete,	NoSymbol,	NoSymbol,	NoSymbol,
    /*  142 */  XK_End,		NoSymbol,	NoSymbol,	NoSymbol,
    /*  143 */  XK_Next,	NoSymbol,	NoSymbol,	NoSymbol,
    /*  144 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*  145 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*  146 */  XK_KP_0,	NoSymbol,	NoSymbol,	NoSymbol,
    /*  147 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*  148 */  XK_KP_Decimal,	NoSymbol,	NoSymbol,	NoSymbol,
    /*  149 */  XK_KP_Enter,	NoSymbol,	NoSymbol,	NoSymbol,
    /*  150 */  XK_KP_1,	NoSymbol,	NoSymbol,	NoSymbol,
    /*  151 */  XK_KP_2,	NoSymbol,	NoSymbol,	NoSymbol,
    /*  152 */  XK_KP_3,	NoSymbol,	NoSymbol,	NoSymbol,
    /*  153 */  XK_KP_4,	NoSymbol,	NoSymbol,	NoSymbol,
    /*  154 */  XK_KP_5,	NoSymbol,	NoSymbol,	NoSymbol,
    /*  155 */  XK_KP_6,	NoSymbol,	NoSymbol,	NoSymbol,
    /*  156 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*  157 */  XK_KP_7,	NoSymbol,	NoSymbol,	NoSymbol,
    /*  158 */  XK_KP_8,	NoSymbol,	NoSymbol,	NoSymbol,
    /*  159 */  XK_KP_9,	NoSymbol,	NoSymbol,	NoSymbol,
    /*  160 */  XK_KP_Subtract, NoSymbol,	NoSymbol,	NoSymbol,
#if 0
    /*  161 */  XK_PF1,         NoSymbol,	NoSymbol,	NoSymbol,
    /*  162 */  XK_PF2,         NoSymbol,	NoSymbol,	NoSymbol,
    /*  163 */  XK_PF3,         NoSymbol,	NoSymbol,	NoSymbol,
    /*  164 */  XK_PF4,         NoSymbol,	NoSymbol,	NoSymbol,
#else
    /*  161 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*  162 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*  163 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*  164 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
#endif
    /*  165 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*  166 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*  167 */  XK_Left,	NoSymbol,	NoSymbol,	NoSymbol,
    /*  168 */  XK_Right,	NoSymbol,	NoSymbol,	NoSymbol,
    /*  169 */  XK_Down,	NoSymbol,	NoSymbol,	NoSymbol,
    /*  170 */  XK_Up,		NoSymbol,	NoSymbol,	NoSymbol,
    /*  171 */  XK_Shift_R,     NoSymbol,	NoSymbol,	NoSymbol,
    /*  172 */  XK_Alt_L,       NoSymbol,	NoSymbol,	NoSymbol,
    /*  173 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*  174 */  XK_Shift_L,     NoSymbol,	NoSymbol,	NoSymbol,
    /*  175 */  XK_Control_L,   NoSymbol,	NoSymbol,	NoSymbol,
    /*  176 */  XK_Caps_Lock,   NoSymbol,	NoSymbol,	NoSymbol,
    /*  177 */  XK_Meta_L,	NoSymbol,	NoSymbol,	NoSymbol,
    /*  178 */  XK_Meta_R,	NoSymbol,	NoSymbol,	NoSymbol,
    /*  179 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*  180 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*  181 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*  182 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*  183 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*  184 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*  185 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*  186 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*  187 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*  188 */  XK_BackSpace,   NoSymbol,	NoSymbol,	NoSymbol,
    /*  189 */  XK_Return,      NoSymbol,	NoSymbol,	NoSymbol,
    /*  190 */  XK_Tab,         NoSymbol,	NoSymbol,	NoSymbol,
    /*  191 */  XK_quoteleft,	XK_asciitilde,	NoSymbol,	NoSymbol,
    /*  192 */  XK_1,           XK_exclam,	NoSymbol,	NoSymbol,
    /*  193 */  XK_Q,           NoSymbol,	NoSymbol,	NoSymbol,
    /*  194 */  XK_A,           NoSymbol,	NoSymbol,	NoSymbol,
    /*  195 */  XK_Z,           NoSymbol,	NoSymbol,	NoSymbol,
    /*  196 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*  197 */  XK_2,           XK_at,		NoSymbol,	NoSymbol,
    /*  198 */  XK_W,           NoSymbol,	NoSymbol,	NoSymbol,
    /*  199 */  XK_S,           NoSymbol,	NoSymbol,	NoSymbol,
    /*  200 */  XK_X,           NoSymbol,	NoSymbol,	NoSymbol,
    /*  201 */  XK_less,	XK_greater,	NoSymbol,	NoSymbol,
    /*  202 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*  203 */  XK_3,           XK_numbersign,	NoSymbol,	NoSymbol,
    /*  204 */  XK_E,           NoSymbol,	NoSymbol,	NoSymbol,
    /*  205 */  XK_D,           NoSymbol,	NoSymbol,	NoSymbol,
    /*  206 */  XK_C,           NoSymbol,	NoSymbol,	NoSymbol,
    /*  207 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*  208 */  XK_4,           XK_dollar,	NoSymbol,	NoSymbol,
    /*  209 */  XK_R,           NoSymbol,	NoSymbol,	NoSymbol,
    /*  210 */  XK_F,           NoSymbol,	NoSymbol,	NoSymbol,
    /*  211 */  XK_V,           NoSymbol,	NoSymbol,	NoSymbol,
    /*  212 */  XK_space,       NoSymbol,	NoSymbol,	NoSymbol,
    /*  213 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*  214 */  XK_5,           XK_percent,	NoSymbol,	NoSymbol,
    /*  215 */  XK_T,           NoSymbol,	NoSymbol,	NoSymbol,
    /*  216 */  XK_G,           NoSymbol,	NoSymbol,	NoSymbol,
    /*  217 */  XK_B,           NoSymbol,	NoSymbol,	NoSymbol,
    /*  218 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*  219 */  XK_6,           XK_asciicircum,	NoSymbol,	NoSymbol,
    /*  220 */  XK_Y,           NoSymbol,	NoSymbol,	NoSymbol,
    /*  221 */  XK_H,           NoSymbol,	NoSymbol,	NoSymbol,
    /*  222 */  XK_N,           NoSymbol,	NoSymbol,	NoSymbol,
    /*  223 */  NoSymbol,       NoSymbol,	NoSymbol,	NoSymbol,
    /*  224 */  XK_7,           XK_ampersand,	NoSymbol,	NoSymbol,
    /*  225 */  XK_U,           NoSymbol,	NoSymbol,	NoSymbol,
    /*  226 */  XK_J,           NoSymbol,	NoSymbol,	NoSymbol,
    /*  227 */  XK_M,           NoSymbol,	NoSymbol,	NoSymbol,
    /*  228 */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /*  229 */  XK_8,           XK_asterisk,	NoSymbol,	NoSymbol,
    /*  230 */  XK_I,           NoSymbol,	NoSymbol,	NoSymbol,
    /*  231 */  XK_K,           NoSymbol,	NoSymbol,	NoSymbol,
    /*  232 */  XK_comma,       XK_less,	NoSymbol,	NoSymbol,
    /*  233 */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /*  234 */  XK_9,           XK_parenleft,	NoSymbol,	NoSymbol,
    /*  235 */  XK_O,           NoSymbol,	NoSymbol,	NoSymbol,
    /*  236 */  XK_L,           NoSymbol,	NoSymbol,	NoSymbol,
    /*  237 */  XK_period,      XK_greater,	NoSymbol,	NoSymbol,
    /*  238 */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /*  239 */  XK_0,           XK_parenright,	NoSymbol,	NoSymbol,
    /*  240 */  XK_P,           NoSymbol,	NoSymbol,	NoSymbol,
    /*  241 */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /*  242 */  XK_semicolon,   XK_colon,	NoSymbol,	NoSymbol,
    /*  243 */  XK_slash,       XK_question,	NoSymbol,	NoSymbol,
    /*  244 */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /*  245 */  XK_equal,       XK_plus,	NoSymbol,	NoSymbol,
    /*  246 */  XK_bracketright,XK_braceright,	NoSymbol,	NoSymbol,
    /*  247 */  XK_backslash,   XK_bar,		NoSymbol,	NoSymbol,
    /*  248 */  NoSymbol,	NoSymbol,	NoSymbol,	NoSymbol,
    /*  249 */  XK_minus,       XK_underscore,	NoSymbol,	NoSymbol,
    /*  250 */  XK_bracketleft, XK_braceleft,	NoSymbol,	NoSymbol,
    /*  251 */  XK_quoteright,  XK_quotedbl,	NoSymbol,	NoSymbol,
};

#define LK201_KEY_R_SHIFT  (171 - 86)
#define LK201_KEY_SHIFT    (174 - 86)
#define LK201_KEY_CAPSLOCK (176 - 86)
#define LK201_KEY_CONTROL  (175 - 86)
#define LK201_KEY_ALT      (177 - 86)

static DecModmapRec lk201modmap[] = {
	LK201_KEY_R_SHIFT,	ShiftMask,
	LK201_KEY_SHIFT,	ShiftMask,
	LK201_KEY_CAPSLOCK,	LockMask,
	LK201_KEY_CONTROL,	ControlMask,
	LK201_KEY_ALT,		Mod1Mask,
	0,			0
};
