// void RegistrarMensaje(int gravedad, const char *funcion, int linea,
//                      const char *mensaje);

/* variante b, funcion de callback (puntero a una funcion)*/
typedef void (*logger_t)(int graveda, const char *funcion, int linea,
                         const char *mensaje);