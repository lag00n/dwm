static const char norm_fg[] = "#282828";
static const char norm_bg[] = "#fbf1c7";
static const char norm_border[] = "#bdae93";

static const char sel_fg[] = "#282828";
static const char sel_bg[] = "#79740e";
static const char sel_border[] = "#282828";

static const char urg_fg[] = "#282828";
static const char urg_bg[] = "#9d0006";
static const char urg_border[] = "#9d0006";

static const char *colors[][3]      = {
    /*               fg           bg         border                         */
    [SchemeNorm] = { norm_fg,     norm_bg,   norm_border }, // unfocused wins
    [SchemeSel]  = { sel_fg,      sel_bg,    sel_border },  // the focused win
    [SchemeUrg] =  { urg_fg,      urg_bg,    urg_border },
};
