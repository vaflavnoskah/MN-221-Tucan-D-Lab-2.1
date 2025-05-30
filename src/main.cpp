#include <Arduino.h>
#include "app_lab_1_1/app_lab_1_1.h"
#include "app_lab_1_1_1/app_lab_1_1_1.h"
#include "app_lab_1_2/app_lab_1_2.h"
#include "app_lab_2_1/app_lab_2_1.h"
#include "app_lab_2_2/app_lab_2_2.h"
#include "app_lab_3_1/app_lab_3_1.h"
#include "app_lab_3_2/app_lab_3_2.h"
#include "app_lab_4_1/app_lab_4_1.h"
#include "app_lab_4_2/app_lab_4_2.h"
#include "app_lab_5_1/app_lab_5_1.h"
#include "app_lab_5_2/app_lab_5_2.h"
#include "app_lab_6_1/app_lab_6_1.h"
#include "app_lab_6_2/app_lab_6_2.h"
#include "app_lab_7_3/app_lab_7_3.h"




#define USE_APP_LAB_1_1 11
#define USE_APP_LAB_1_1_1 111
#define USE_APP_LAB_1_2 12
#define USE_APP_LAB_2_1 21
#define USE_APP_LAB_2_2 22
#define USE_APP_LAB_3_1 31
#define USE_APP_LAB_3_2 32
#define USE_APP_LAB_4_1 41
#define USE_APP_LAB_4_2 42
#define USE_APP_LAB_5_1 51
#define USE_APP_LAB_5_2 52
#define USE_APP_LAB_6_1 61
#define USE_APP_LAB_6_2 62
#define USE_APP_LAB_7_3 73


#define APP_USED USE_APP_LAB_6_1

void setup()
{
#if APP_USED == USE_APP_LAB_1_1
    app_lab_1_1_setup();
    
#elif APP_USED == USE_APP_LAB_1_1_1
    app_lab_1_1_1_setup();

#elif APP_USED == USE_APP_LAB_1_2
    app_lab_1_2_setup();
#elif APP_USED == USE_APP_LAB_2_2
    app_lab_2_2_setup();
#elif APP_USED == USE_APP_LAB_3_1
    app_lab_3_1_setup();
#elif APP_USED == USE_APP_LAB_3_2
    app_lab_3_2_setup();
#elif APP_USED == USE_APP_LAB_4_1
    app_lab_4_1_setup();
#elif APP_USED == USE_APP_LAB_4_2
    app_lab_4_2_setup();
#elif APP_USED == USE_APP_LAB_5_1
    app_lab_5_1_setup();
#elif APP_USED == USE_APP_LAB_5_2
    app_lab_5_2_setup();
#elif APP_USED == USE_APP_LAB_6_1
    app_lab_6_1_setup();
#elif APP_USED == USE_APP_LAB_6_2
    app_lab_6_2_setup();
#elif APP_USED == USE_APP_LAB_7_3
    app_lab_7_3_setup();

#endif

}

void loop()
{
#if APP_USED == USE_APP_LAB_1_1
    app_lab_1_1_loop();
#endif

#if APP_USED == USE_APP_LAB_1_1_1
    app_lab_1_1_1_loop();

#endif

#if APP_USED == USE_APP_LAB_1_2
    app_lab_1_2_loop();
#endif

#if APP_USED == USE_APP_LAB_2_1
    app_lab_2_1_loop();
#endif

#if APP_USED == USE_APP_LAB_2_2
    app_lab_2_2_loop();
#endif

#if APP_USED == USE_APP_LAB_3_1
    app_lab_3_1_loop();
#endif

#if APP_USED == USE_APP_LAB_3_2
    app_lab_3_2_loop();
#endif

#if APP_USED == USE_APP_LAB_4_1
    app_lab_4_1_loop();
#endif

#if APP_USED == USE_APP_LAB_4_2
    app_lab_4_2_loop();
#endif

#if APP_USED == USE_APP_LAB_5_1
    app_lab_5_1_loop();
#endif

#if APP_USED == USE_APP_LAB_5_2
    app_lab_5_2_loop();
#endif

#if APP_USED == USE_APP_LAB_6_1
    app_lab_6_1_loop();
#endif

#if APP_USED == USE_APP_LAB_6_2
    app_lab_6_2_loop();
#endif

#if APP_USED == USE_APP_LAB_7_3
    app_lab_7_3_loop();

#endif


}