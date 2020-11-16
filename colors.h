static const char norm_fg[] = "#e8bcb1";
static const char norm_bg[] = "#150f14";
static const char norm_border[] = "#a2837b";

static const char sel_fg[] = "#e8bcb1";
static const char sel_bg[] = "#875B54";
static const char sel_border[] = "#e8bcb1";

static const char urg_fg[] = "#e8bcb1";
static const char urg_bg[] = "#964536";
static const char urg_border[] = "#964536";

static const char unseltag[] = "#c44b36"; // cor da fonte da tag inativa
static const char activetag[] = "#f9d25b"; // cor da fonte da tag ativa
static const char barbg[] = "#1e1e1e";

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
