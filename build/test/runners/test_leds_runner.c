/* AUTOGENERATED FILE. DO NOT EDIT. */

/*=======Automagically Detected Files To Include=====*/
#include "unity.h"

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

/*=======External Functions This Runner Calls=====*/
extern void setUp(void);
extern void tearDown(void);
extern void test_todos_los_leds_inician_apagados(void);
extern void test_prender_un_led();
extern void test_apagar_un_led(void);
extern void test_prender_y_apagar_varios_leds(void);
extern void test_error_en_parametro(void);
extern void test_error_encender_todos_leds(void);
extern void test_error_apagar_todos_leds(void);
extern void test_estado_encendido(void);
extern void test_estado_apagado(void);


/*=======Mock Management=====*/
static void CMock_Init(void)
{
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
  GlobalOrderError = NULL;
}
static void CMock_Verify(void)
{
}
static void CMock_Destroy(void)
{
}

/*=======Teardown (stub)=====*/
void tearDown(void) {}

/*=======Test Reset Options=====*/
void resetTest(void);
void resetTest(void)
{
  tearDown();
  CMock_Verify();
  CMock_Destroy();
  CMock_Init();
  setUp();
}
void verifyTest(void);
void verifyTest(void)
{
  CMock_Verify();
}

/*=======Test Runner Used To Run Each Test=====*/
static void run_test(UnityTestFunction func, const char* name, UNITY_LINE_TYPE line_num)
{
    Unity.CurrentTestName = name;
    Unity.CurrentTestLineNumber = line_num;
#ifdef UNITY_USE_COMMAND_LINE_ARGS
    if (!UnityTestMatches())
        return;
#endif
    Unity.NumberOfTests++;
    UNITY_CLR_DETAILS();
    UNITY_EXEC_TIME_START();
    CMock_Init();
    if (TEST_PROTECT())
    {
        setUp();
        func();
    }
    if (TEST_PROTECT())
    {
        tearDown();
        CMock_Verify();
    }
    CMock_Destroy();
    UNITY_EXEC_TIME_STOP();
    UnityConcludeTest();
}

/*=======MAIN=====*/
int main(void)
{
  UnityBegin("test_leds.c");
  run_test(test_todos_los_leds_inician_apagados, "test_todos_los_leds_inician_apagados", 49);
  run_test(test_prender_un_led, "test_prender_un_led", 59);
  run_test(test_apagar_un_led, "test_apagar_un_led", 66);
  run_test(test_prender_y_apagar_varios_leds, "test_prender_y_apagar_varios_leds", 74);
  run_test(test_error_en_parametro, "test_error_en_parametro", 84);
  run_test(test_error_encender_todos_leds, "test_error_encender_todos_leds", 99);
  run_test(test_error_apagar_todos_leds, "test_error_apagar_todos_leds", 106);
  run_test(test_estado_encendido, "test_estado_encendido", 113);
  run_test(test_estado_apagado, "test_estado_apagado", 119);

  return UnityEnd();
}
