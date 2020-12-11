static const char norm_fg[] = "#282828";
static const char norm_bg[] = "#fbf1c7";
static const char norm_border[] = "#bdae93";

static const char sel_fg[] = "#282828";
static const char sel_bg[] = "#79740e";
static const char sel_border[] = "#282828";

static const char urg_fg[] = "#282828";
static const char urg_bg[] = "#9d0006";
static const char urg_border[] = "#9d0006";

static const char unseltag[] = "#9d0006"; // cor da fonte da tag inativa
static const char activetag[] = "#79740e"; // cor da fonte da tag ativa
static const char barbg[] = "#fbf1c7";

static const char *colors[][3]      = {
    /*               fg           bg         border                         */
    [SchemeNorm] = { norm_fg,     norm_bg,   norm_border }, // unfocused wins
    [SchemeSel]  = { sel_fg,      sel_bg,    sel_border },  // the focused win
    [SchemeStatus] =  { unseltag,    barbg,  "#000000" }, // Statusbar right (text background)
    [SchemeTagsSel] = { activetag,  barbg, "#000000" }, //Tagbar left selected (text,Background)
    [SchemeTagsNorm]  = { unseltag, barbg,  "#000000"  }, // Tagbar left unselected {text,background,not used but cannot be empty}
    [SchemeInfoSel]  = { unseltag, barbg,  "#000000"  }, // infobar middle  selected {text,background,not used but cannot be empty}
    [SchemeInfoNorm]  = { unseltag, barbg,  "#000000"  }, // infobar middle  unselected {text,background,not used but cannot be empty}
};
