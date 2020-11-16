/* See LICENSE file for copyright and license details. */
/* appearance */
static const unsigned int borderpx  = 5;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int horizpadbar        = 10;        /* padding horizontal interno da barra */
static const int vertpadbar         = 13;        /* padding vertical interno da barra */
static const int vertpad            = 10;        // vertical padding of bar
static const int sidepad            = 10;        // horizontal padding of bar
static const unsigned int gappih    = 10;        // horiz inner gap 
static const unsigned int gappiv    = 10;        // vert inner gap 
static const unsigned int gappoh    = 10;        // horiz outer gap 
static const unsigned int gappov    = 10;        // vert outer gap
static const int smartgaps          = 0;        // smartgaps = 1 = ligado 
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int swallowfloating    = 1;        /* 1 means swallow floating. */
static const char *fonts[]          = { "terminus:size=9:bold"};
static const char dmenufont[]       = "cherry:size=10";
static const char dmenulines[]      = "20";

/* autostart */
static const char *const autostart[] = {
//  "dwmblocks", NULL,
  "dwmblocks", NULL,
  "feh", "--bg-fil", "/home/murilo/Imagens/Wallpapers/bowser.jpg", NULL,
  "xrdb", "/home/murilo/.Xresources", NULL,
  NULL /* terminate */
};


/* scratchpads configuration */
typedef struct {
	const char *name;
	const void *cmd;
} Sp;

const char *telegram[] = {"Telegram", NULL };
const char *ranger[] = {"st", "-n", "ranger", "-g", "144x41", "-e", "ranger", NULL };
const char *calcurse[] = {"st", "-n", "calcurse", "-g", "144x41", "-e", "calcurse", NULL};
const char *spotify[] = { "spotify", NULL };

static Sp scratchpads[] = {
	/* name          cmd  */
  {"Telegram",    telegram},
  {"ranger",      ranger},
  {"calcurse",    calcurse},
};

/* launchers */
//o spotify já foi declarado em scratchpads.

static const Launcher launchers[] = {
  /* command      nome */
 { spotify,      "\uf9c6" },
};


#include "/home/murilo/github/dwm-6.2/colors.h" // adding colorscheme :D 
//#include "/home/murilo/.cache/wal/colors-wal-dwm.h" 

/* tagging */
static const char *tags[] = { "一", "二", "三", "四", "五", "六", "七", "八", "九" };
//static const char *tags[] = { "\e0071",};

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask  iscentered   isfloating   monitor */   
	{ "Gimp",     NULL,       NULL,       0,         0,             1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 2,    0,             0,           -1 },
  { "st",       "St",       NULL,       2,         0,             0,           -1 },
  { "feh",      NULL,       NULL,       0,         1,             1,           -1 },
/* scratchpads */
  { NULL,       "Telegram", NULL,       SPTAG(0),  1,             1,           -1 },
  { NULL,       "ranger",   NULL,       SPTAG(1),  1,             1,           -1 },
  { NULL,       "calcurse", NULL,       SPTAG(2),  1,             1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

#include "gaplessgrid.c" /* gapless layout patch. */
#include "fibonacci.c" /* dwindle and spiral layouts patch. */
static const Layout layouts[] = {
	/* symbol     arrange function */
	//{ "| [tile]",      tile },    /* first entry is default */
  { "| [tile]",           tile },
  { "| [floating]",      NULL },    /* no layout function means floating behavior */
	{ "| [monocle]",      monocle },
  { "| [spiral]",      spiral },
  { "| [dwindle]",      dwindle },
  { "| [grid]", gaplessgrid },
  { "| |M|", centeredmaster },
  { "| >M>", centeredfloatingmaster },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* paradinha pra spawnar comando na shell  */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

//commands
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "/home/murilo/.local/bin/dmenu_run","-m", dmenumon, "-fn", dmenufont, "-l", dmenulines, NULL };
static const char *termcmd[]  = { "st", "-n", "St", NULL };
static const char *firefox[] = { "firefox-bin", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
/* spawn commands */	
  { MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
  { MODKEY|ShiftMask,             XK_f,      spawn,          {.v = firefox} },
  { MODKEY,                       XK_v,      spawn,          SHCMD("maim -s | xclip -selection clipboard -t image/png") }, // printscreen ( tempscrot ) 
  { MODKEY,                       XK_x,      spawn,          SHCMD("redshift -O 4000") },
  { MODKEY|ShiftMask,             XK_x,      spawn,          SHCMD("redshift -x") }, 
/*scratchpads*/
  { MODKEY|ShiftMask,             XK_t,      togglescratch,  {.ui = 0 } },
  { MODKEY,                       XK_z,      togglescratch,  {.ui = 1 } },
  { MODKEY,                       XK_c,      togglescratch,  {.ui = 2 } },
/*misc*/
  { MODKEY,                       XK_b,      togglebar,      {0} },	
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
  { MODKEY,                       XK_Right,  focusstack,     {.i = -1 } },
  { MODKEY,                       XK_Left,   focusstack,     {.i = +1 } },
  { MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_w,      killclient,     {-1} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
  { MODKEY,                       XK_r,      setlayout,      {.v = &layouts[3]} },
  { MODKEY|ShiftMask,             XK_r,      setlayout,      {.v = &layouts[4]} },
  { MODKEY,                       XK_g,      setlayout,      {.v = &layouts[5]} },
  { MODKEY,                       XK_u,      setlayout,      {.v = &layouts[6]} }, 
  { MODKEY|ShiftMask,             XK_u,      setlayout,      {.v = &layouts[7]} },
  { MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
  { MODKEY|Mod1Mask,              XK_h,      incrgaps,       {.i = +5 } },
  { MODKEY|Mod1Mask,              XK_l,      incrgaps,       {.i = -5 } },
  { MODKEY|Mod1Mask,              XK_0,      defaultgaps,    {0} },
  { MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
  TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
  { MODKEY|ShiftMask|ControlMask, XK_q,      quit,           {1} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
