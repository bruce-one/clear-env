#include <node_api.h>
#include <string.h>

extern char **environ;
inline void clearEnv() {
  char** envp = environ;
  while (*envp) {
    memset(*envp, 0, strlen(*envp));
    envp++;
  }
}

napi_value ClearEnv(napi_env env, napi_callback_info args) {
  clearEnv();
  napi_value res;
  napi_get_boolean(env, true, &res);
  return res;
}

napi_value init(napi_env env, napi_value exports) {
  napi_status status;
  napi_value fn;

  status = napi_create_function(env, NULL, 0, ClearEnv, NULL, &fn);
  if (status != napi_ok) return NULL;

  return fn;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, init)
