#include <furi.h>
#include <gui/gui.h>
#include <gui/view_dispatcher.h>
#include <gui/modules/submenu.h>

typedef enum {
    FretLabMenuTuner = 0,
    FretLabMenuMetronome,
    FretLabMenuTapTempo,
} FretLabMenuItem;

typedef struct {
    ViewDispatcher* view_dispatcher;
    Submenu* submenu;
} FretLabApp;

static uint32_t fretlab_exit_callback(void* context) {
    UNUSED(context);
    return VIEW_NONE;
}

static void fretlab_menu_callback(void* context, uint32_t index) {
    FretLabApp* app = context;

    switch(index) {
    case FretLabMenuTuner:
        submenu_set_header(app->submenu, "Tuner - Coming Soon");
        break;

    case FretLabMenuMetronome:
        submenu_set_header(app->submenu, "Metronome - Coming Soon");
        break;

    case FretLabMenuTapTempo:
        submenu_set_header(app->submenu, "Tap Tempo - Coming Soon");
        break;

    default:
        break;
    }
}

int32_t fretlab_app(void* p) {
    UNUSED(p);

    FretLabApp* app = malloc(sizeof(FretLabApp));

    app->view_dispatcher = view_dispatcher_alloc();
    app->submenu = submenu_alloc();

    view_dispatcher_enable_queue(app->view_dispatcher);

    Gui* gui = furi_record_open(RECORD_GUI);

    view_dispatcher_attach_to_gui(
        app->view_dispatcher,
        gui,
        ViewDispatcherTypeFullscreen);

    submenu_set_header(app->submenu, "FretLab");

    submenu_add_item(
        app->submenu,
        "Guitar Tuner",
        FretLabMenuTuner,
        fretlab_menu_callback,
        app);

    submenu_add_item(
        app->submenu,
        "Metronome",
        FretLabMenuMetronome,
        fretlab_menu_callback,
        app);

    submenu_add_item(
        app->submenu,
        "Tap Tempo",
        FretLabMenuTapTempo,
        fretlab_menu_callback,
        app);

    view_set_previous_callback(
        submenu_get_view(app->submenu),
        fretlab_exit_callback);

    view_dispatcher_add_view(
        app->view_dispatcher,
        0,
        submenu_get_view(app->submenu));

    view_dispatcher_switch_to_view(app->view_dispatcher, 0);

    view_dispatcher_run(app->view_dispatcher);

    view_dispatcher_remove_view(app->view_dispatcher, 0);

    submenu_free(app->submenu);
    view_dispatcher_free(app->view_dispatcher);

    furi_record_close(RECORD_GUI);

    free(app);

    return 0;
}
