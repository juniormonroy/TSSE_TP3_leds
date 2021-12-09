/*
 *1 Despues de la configuracion todos los leds deben quedar apagados

 *2 Prender un led cualquiera

 *3 Apagar un led cualquiera

 *4 Prender y apagar algunos leds

 *5 Prender todos los leds juntos
 *6 Apagar todos los leds juntos
 *7 Consultar el estado de un leds apagado
 *8 Consultar el estado de un led encendido

 *9 Revisar los valores limites de los parametros obc

 *10Probar valores invalidos para los parametros
 */
#include "leds.h"
//#include "mock_errores.h"
#include "unity.h"
#include <string.h>

#define LED 3
#define LED_BIT(x) (1 << (x - 1))

static uint16_t puertoVirtual;
static struct {
  int gravedad;
  char funcion[64];

} error;
void RegistrarMensaje(int gravedad, const char *funcion, int linea,
                      const char *mensaje) {
  error.gravedad = gravedad;
  strcpy(error.funcion, funcion);
}

// funcion para configuraciones comunes a las demas, var globales
void setUp(void) {

  error.gravedad = -1;
  memset(error.funcion, 0, sizeof(error.funcion));

  LedsCreate(&puertoVirtual, RegistrarMensaje);
}

/* 1 Despues de la configuracion todos los leds deben quedar apagados*/
void test_todos_los_leds_inician_apagados(void) {

  // queda explicito el test a si dejaramos solo
  // "TEST_ASSERT_EQUAL_HEX16(0X0000, puertoVirtual)"
  uint16_t puertoVirtual = 0xFFFF;
  LedsCreate(&puertoVirtual, RegistrarMensaje);
  TEST_ASSERT_EQUAL_HEX16(0X0000, puertoVirtual);
}

/* 2 Prender un led cualquiera*/
void test_prender_un_led() {

  LedsOn(LED);
  TEST_ASSERT_EQUAL_HEX16(LED_BIT(LED), puertoVirtual);
}

/* 3 Apagar un led cualquiera*/
void test_apagar_un_led(void) {

  LedsOn(LED);
  LedsOff(LED); // funcion
  TEST_ASSERT_EQUAL_HEX16(0x0000, puertoVirtual);
}

/* 4 Prender y apagar algunos leds */
void test_prender_y_apagar_varios_leds(void) {

  LedsOn(LED);
  LedsOn(LED + 3);
  LedsOff(LED);
  TEST_ASSERT_EQUAL_HEX16(LED_BIT(LED + 3),
                          puertoVirtual); // SE ESPERA LED + 3 SIGA ENCENDIDO
}

/* 10 Probar valores invalidos para los parametros*/
void test_error_en_parametro(void) {

  // RegistrarMensaje_Expect(0, "LedsOn", 0, "Numero de led Invalido");
  // RegistrarMensaje_IgnoreArg_linea();
  LedsOn(17);
  TEST_ASSERT_EQUAL(0, error.gravedad); // si llama , sale aca
  TEST_ASSERT_EQUAL_STRING("LedsOn", error.funcion);

  // error.gravedad = -1;
  // memset(error.funcion, 0, sizeof(error.funcion));

  LedsOn(0);
  TEST_ASSERT_EQUAL(0, error.gravedad);
  TEST_ASSERT_EQUAL_STRING("LedsOn", error.funcion);
}
