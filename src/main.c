#include <pebble.h>

static Window *s_main_window;
static TextLayer *s_time_layer;
static TextLayer *s_quote1_layer;
static TextLayer *s_quote2_layer; 
static TextLayer *s_quote3_layer;
  
// HARDCODED NONESENSE BECUASE VIBES ARE WEIRD
static const uint32_t segs0100[] = { 1500, 500, 750, 500, 750, 500, 750, 3000, 1000 };
static const uint32_t segs0200[] = { 1500, 500, 750, 500, 750, 500, 750, 3000, 1000, 1000, 1000 };
static const uint32_t segs0300[] = { 1500, 500, 750, 500, 750, 500, 750, 3000, 1000, 1000, 1000, 1000, 1000 };
static const uint32_t segs0400[] = { 1500, 500, 750, 500, 750, 500, 750, 3000, 1000, 1000, 1000, 1000, 1000, 1000, 1000 };
static const uint32_t segs0500[] = { 1500, 500, 750, 500, 750, 500, 750, 3000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000 };
static const uint32_t segs0600[] = { 1500, 500, 750, 500, 750, 500, 750, 3000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000 };
static const uint32_t segs0700[] = { 1500, 500, 750, 500, 750, 500, 750, 3000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000 };
static const uint32_t segs0800[] = { 1500, 500, 750, 500, 750, 500, 750, 3000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000 };
static const uint32_t segs0900[] = { 1500, 500, 750, 500, 750, 500, 750, 3000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000 };
static const uint32_t segs1000[] = { 1500, 500, 750, 500, 750, 500, 750, 3000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000 };
static const uint32_t segs1100[] = { 1500, 500, 750, 500, 750, 500, 750, 3000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000};
static const uint32_t segs1200[] = { 1500, 500, 750, 500, 750, 500, 750, 3000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000 };

static const uint32_t segs0115[] = {750, 500, 1500, 500, 750, 500, 750, 3000, 1000 };
static const uint32_t segs0215[] = {750, 500, 1500, 500, 750, 500, 750, 3000, 1000, 1000, 1000 };
static const uint32_t segs0315[] = {750, 500, 1500, 500, 750, 500, 750, 3000, 1000, 1000, 1000, 1000, 1000 };
static const uint32_t segs0415[] = {750, 500, 1500, 500, 750, 500, 750, 3000, 1000, 1000, 1000, 1000, 1000, 1000, 1000 };
static const uint32_t segs0515[] = {750, 500, 1500, 500, 750, 500, 750, 3000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000 };
static const uint32_t segs0615[] = {750, 500, 1500, 500, 750, 500, 750, 3000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000 };
static const uint32_t segs0715[] = {750, 500, 1500, 500, 750, 500, 750, 3000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000 };
static const uint32_t segs0815[] = {750, 500, 1500, 500, 750, 500, 750, 3000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000 };
static const uint32_t segs0915[] = {750, 500, 1500, 500, 750, 500, 750, 3000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000 };
static const uint32_t segs1015[] = {750, 500, 1500, 500, 750, 500, 750, 3000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000 };
static const uint32_t segs1115[] = {750, 500, 1500, 500, 750, 500, 750, 3000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000};
static const uint32_t segs1215[] = {750, 500, 1500, 500, 750, 500, 750, 3000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000 };

static const uint32_t segs0130[] = { 750, 500, 750, 500, 1500, 500, 750, 3000, 1000 };
static const uint32_t segs0230[] = { 750, 500, 750, 500, 1500, 500, 750, 3000, 1000, 1000, 1000 };
static const uint32_t segs0330[] = { 750, 500, 750, 500, 1500, 500, 750, 3000, 1000, 1000, 1000, 1000, 1000 };
static const uint32_t segs0430[] = { 750, 500, 750, 500, 1500, 500, 750, 3000, 1000, 1000, 1000, 1000, 1000, 1000, 1000 };
static const uint32_t segs0530[] = { 750, 500, 750, 500, 1500, 500, 750, 3000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000 };
static const uint32_t segs0630[] = { 750, 500, 750, 500, 1500, 500, 750, 3000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000 };
static const uint32_t segs0730[] = { 750, 500, 750, 500, 1500, 500, 750, 3000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000 };
static const uint32_t segs0830[] = { 750, 500, 750, 500, 1500, 500, 750, 3000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000 };
static const uint32_t segs0930[] = { 750, 500, 750, 500, 1500, 500, 750, 3000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000 };
static const uint32_t segs1030[] = { 750, 500, 750, 500, 1500, 500, 750, 3000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000 };
static const uint32_t segs1130[] = { 750, 500, 750, 500, 1500, 500, 750, 3000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000};
static const uint32_t segs1230[] = { 750, 500, 750, 500, 1500, 500, 750, 3000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000 };

static const uint32_t segs0145[] = { 750, 500, 750, 500, 750, 500, 1500, 3000, 1000 };
static const uint32_t segs0245[] = { 750, 500, 750, 500, 750, 500, 1500, 3000, 1000, 1000, 1000 };
static const uint32_t segs0345[] = { 750, 500, 750, 500, 750, 500, 1500, 3000, 1000, 1000, 1000, 1000, 1000 };
static const uint32_t segs0445[] = { 750, 500, 750, 500, 750, 500, 1500, 3000, 1000, 1000, 1000, 1000, 1000, 1000, 1000 };
static const uint32_t segs0545[] = { 750, 500, 750, 500, 750, 500, 1500, 3000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000 };
static const uint32_t segs0645[] = { 750, 500, 750, 500, 750, 500, 1500, 3000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000 };
static const uint32_t segs0745[] = { 750, 500, 750, 500, 750, 500, 1500, 3000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000 };
static const uint32_t segs0845[] = { 750, 500, 750, 500, 750, 500, 1500, 3000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000 };
static const uint32_t segs0945[] = { 750, 500, 750, 500, 750, 500, 1500, 3000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000 };
static const uint32_t segs1045[] = { 750, 500, 750, 500, 750, 500, 1500, 3000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000 };
static const uint32_t segs1145[] = { 750, 500, 750, 500, 750, 500, 1500, 3000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000};
static const uint32_t segs1245[] = { 750, 500, 750, 500, 750, 500, 1500, 3000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000 };

static void update_time() {
  // Get a tm structure
  time_t temp = time(NULL); 
  struct tm *tick_time = localtime(&temp);

  // Write the current hours and minutes into a buffer
  static char s_buffer[8];
  strftime(s_buffer, sizeof(s_buffer), clock_is_24h_style() ?
                                          "%H:%M" : "%I:%M", tick_time);
  // gets hour and minutes
  int hour = tick_time->tm_hour;
  int minutes = tick_time->tm_min;
  
  VibePattern ring;
  bool pleaseRing = false;
        
  if (minutes == 0) {
    pleaseRing = true;
    if (hour % 12 == 0) {
      ring.durations = segs1200;
      ring.num_segments = ARRAY_LENGTH(segs1200);
    } else if (hour % 12 == 1) {
      ring.durations = segs0100;
      ring.num_segments = ARRAY_LENGTH(segs0100);
    } else if (hour % 12 == 2) {
      ring.durations = segs0200;
      ring.num_segments = ARRAY_LENGTH(segs0200);
    } else if (hour % 12 == 3) {
      ring.durations = segs0300;
      ring.num_segments = ARRAY_LENGTH(segs0300);
    } else if (hour % 12 == 4) {
      ring.durations = segs0400;
      ring.num_segments = ARRAY_LENGTH(segs0400);
    } else if (hour % 12 == 5) {
      ring.durations = segs0500;
      ring.num_segments = ARRAY_LENGTH(segs0500);
    } else if (hour % 12 == 6) {
      ring.durations = segs0600;
      ring.num_segments = ARRAY_LENGTH(segs0600);
    } else if (hour % 12 == 7) {
      ring.durations = segs0700;
      ring.num_segments = ARRAY_LENGTH(segs0700);
    } else if (hour % 12 == 8) {
      ring.durations = segs0800;
      ring.num_segments = ARRAY_LENGTH(segs0800);
    } else if (hour % 12 == 9) {
      ring.durations = segs0900;
      ring.num_segments = ARRAY_LENGTH(segs0900);
    } else if (hour % 12 == 10) {
      ring.durations = segs1000;
      ring.num_segments = ARRAY_LENGTH(segs1000);
    } else if (hour % 12 == 11) {
      ring.durations = segs1100;
      ring.num_segments = ARRAY_LENGTH(segs1100);
    }
  } else if(minutes == 15) {
    pleaseRing = true;
    if (hour % 12 == 0) {
      ring.durations = segs1215;
      ring.num_segments = ARRAY_LENGTH(segs1215);
    } else if (hour % 12 == 1) {
      ring.durations = segs0115;
      ring.num_segments = ARRAY_LENGTH(segs0115);
    } else if (hour % 12 == 2) {
      ring.durations = segs0215;
      ring.num_segments = ARRAY_LENGTH(segs0215);
    } else if (hour % 12 == 3) {
      ring.durations = segs0315;
      ring.num_segments = ARRAY_LENGTH(segs0315);
    } else if (hour % 12 == 4) {
      ring.durations = segs0415;
      ring.num_segments = ARRAY_LENGTH(segs0415);
    } else if (hour % 12 == 5) {
      ring.durations = segs0515;
      ring.num_segments = ARRAY_LENGTH(segs0515);
    } else if (hour % 12 == 6) {
      ring.durations = segs0615;
      ring.num_segments = ARRAY_LENGTH(segs0615);
    } else if (hour % 12 == 7) {
      ring.durations = segs0715;
      ring.num_segments = ARRAY_LENGTH(segs0715);
    } else if (hour % 12 == 8) {
      ring.durations = segs0815;
      ring.num_segments = ARRAY_LENGTH(segs0815);
    } else if (hour % 12 == 9) {
      ring.durations = segs0915;
      ring.num_segments = ARRAY_LENGTH(segs0915);
    } else if (hour % 12 == 10) {
      ring.durations = segs1015;
      ring.num_segments = ARRAY_LENGTH(segs1015);
    } else if (hour % 12 == 11) {
      ring.durations = segs1115;
      ring.num_segments = ARRAY_LENGTH(segs1115);
    }
  } else if(minutes == 30) {
    pleaseRing = true;
    if (hour % 12 == 0) {
      ring.durations = segs1230;
      ring.num_segments = ARRAY_LENGTH(segs1230);
    } else if (hour % 12 == 1) {
      ring.durations = segs0130;
      ring.num_segments = ARRAY_LENGTH(segs0130);
    } else if (hour % 12 == 2) {
      ring.durations = segs0230;
      ring.num_segments = ARRAY_LENGTH(segs0230);
    } else if (hour % 12 == 3) {
      ring.durations = segs0330;
      ring.num_segments = ARRAY_LENGTH(segs0330);
    } else if (hour % 12 == 4) {
      ring.durations = segs0430;
      ring.num_segments = ARRAY_LENGTH(segs0430);
    } else if (hour % 12 == 5) {
      ring.durations = segs0530;
      ring.num_segments = ARRAY_LENGTH(segs0530);
    } else if (hour % 12 == 6) {
      ring.durations = segs0630;
      ring.num_segments = ARRAY_LENGTH(segs0630);
    } else if (hour % 12 == 7) {
      ring.durations = segs0730;
      ring.num_segments = ARRAY_LENGTH(segs0730);
    } else if (hour % 12 == 8) {
      ring.durations = segs0830;
      ring.num_segments = ARRAY_LENGTH(segs0830);
    } else if (hour % 12 == 9) {
      ring.durations = segs0930;
      ring.num_segments = ARRAY_LENGTH(segs0930);
    } else if (hour % 12 == 10) {
      ring.durations = segs1030;
      ring.num_segments = ARRAY_LENGTH(segs1030);
    } else if (hour % 12 == 11) {
      ring.durations = segs1130;
      ring.num_segments = ARRAY_LENGTH(segs1130);
    }
  } else if (minutes == 45) {
    pleaseRing = true;
    if (hour % 12 == 0) {
      ring.durations = segs1245;
      ring.num_segments = ARRAY_LENGTH(segs1245);
    } else if (hour % 12 == 1) {
      ring.durations = segs0145;
      ring.num_segments = ARRAY_LENGTH(segs0145);
    } else if (hour % 12 == 2) {
      ring.durations = segs0245;
      ring.num_segments = ARRAY_LENGTH(segs0245);
    } else if (hour % 12 == 3) {
      ring.durations = segs0345;
      ring.num_segments = ARRAY_LENGTH(segs0345);
    } else if (hour % 12 == 4) {
      ring.durations = segs0445;
      ring.num_segments = ARRAY_LENGTH(segs0445);
    } else if (hour % 12 == 5) {
      ring.durations = segs0545;
      ring.num_segments = ARRAY_LENGTH(segs0545);
    } else if (hour % 12 == 6) {
      ring.durations = segs0645;
      ring.num_segments = ARRAY_LENGTH(segs0645);
    } else if (hour % 12 == 7) {
      ring.durations = segs0745;
      ring.num_segments = ARRAY_LENGTH(segs0745);
    } else if (hour % 12 == 8) {
      ring.durations = segs0845;
      ring.num_segments = ARRAY_LENGTH(segs0845);
    } else if (hour % 12 == 9) {
      ring.durations = segs0945;
      ring.num_segments = ARRAY_LENGTH(segs0945);
    } else if (hour % 12 == 10) {
      ring.durations = segs1045;
      ring.num_segments = ARRAY_LENGTH(segs1045);
    } else if (hour % 12 == 11) {
      ring.durations = segs1145;
      ring.num_segments = ARRAY_LENGTH(segs1145);
    }
  }
  
  // DO NOT WAKE UP MID-NIGHT
  if (hour < 8) {
    pleaseRing = false;
  }
  
  if (pleaseRing == true) vibes_enqueue_custom_pattern(ring);
  
  // Display this time on the TextLayer
  text_layer_set_text(s_time_layer, s_buffer);
}

static void tick_handler(struct tm *tick_time, TimeUnits units_changed) {
  update_time();
}

static void main_window_load(Window *window) {
  // Get information about the Window
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);

  // PASS ME THE VIBES
  s_quote1_layer = text_layer_create (
    GRect(0, PBL_IF_ROUND_ELSE(30, 20), bounds.size.w, 50));
  text_layer_set_background_color(s_quote1_layer, GColorClear);
  text_layer_set_text_color(s_quote1_layer, GColorBlack);
  text_layer_set_text(s_quote1_layer, "pass me the vibes");
  text_layer_set_font(s_quote1_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24));
  text_layer_set_text_alignment(s_quote1_layer, GTextAlignmentCenter);
  
  // WATCHFACE LAYER
  s_time_layer = text_layer_create(
      GRect(0, PBL_IF_ROUND_ELSE(54, 44), bounds.size.w, 50));
  text_layer_set_background_color(s_time_layer, GColorClear);
  text_layer_set_text_color(s_time_layer, GColorBlack);
  text_layer_set_text(s_time_layer, "00:00");
  text_layer_set_font(s_time_layer, fonts_get_system_font(FONT_KEY_BITHAM_42_LIGHT));
  text_layer_set_text_alignment(s_time_layer, GTextAlignmentCenter);
  
  // I WANT TO PLAY THE 
  s_quote2_layer = text_layer_create (
    GRect(0, PBL_IF_ROUND_ELSE(98, 88), bounds.size.w, 50));
  text_layer_set_background_color(s_quote2_layer, GColorClear);
  text_layer_set_text_color(s_quote2_layer, GColorBlack);
  text_layer_set_text(s_quote2_layer, "i want to play the");
  text_layer_set_font(s_quote2_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24));
  text_layer_set_text_alignment(s_quote2_layer, GTextAlignmentCenter);
  
  // VIBRAPHONE
  s_quote3_layer = text_layer_create (
    GRect(0, PBL_IF_ROUND_ELSE(118, 108), bounds.size.w, 50));
  text_layer_set_background_color(s_quote3_layer, GColorClear);
  text_layer_set_text_color(s_quote3_layer, GColorBlack);
  text_layer_set_text(s_quote3_layer, "VIBRAPHONE");
  text_layer_set_font(s_quote3_layer, fonts_get_system_font(FONT_KEY_GOTHIC_28));
  text_layer_set_text_alignment(s_quote3_layer, GTextAlignmentCenter);
  
  // ADD LAYERS
  layer_add_child(window_layer, text_layer_get_layer(s_quote1_layer));
  layer_add_child(window_layer, text_layer_get_layer(s_time_layer));
  layer_add_child(window_layer, text_layer_get_layer(s_quote2_layer));
  layer_add_child(window_layer, text_layer_get_layer(s_quote3_layer));
}

static void main_window_unload(Window *window) {
  // Destroy TextLayer
  text_layer_destroy(s_time_layer);
}


static void init() {
  // Create main Window element and assign to pointer
  s_main_window = window_create();

  // Set handlers to manage the elements inside the Window
  window_set_window_handlers(s_main_window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload
  });

  // Show the Window on the watch, with animated=true
  window_stack_push(s_main_window, true);

  // Make sure the time is displayed from the start
  update_time();

  // Register with TickTimerService
  tick_timer_service_subscribe(MINUTE_UNIT, tick_handler);
}

static void deinit() {
  // Destroy Window
  window_destroy(s_main_window);
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}