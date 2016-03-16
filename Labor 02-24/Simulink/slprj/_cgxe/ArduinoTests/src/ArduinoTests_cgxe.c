/* Include files */

#include "ArduinoTests_cgxe.h"
#include "m_ghzL9u6H4AUvnUT3cRQ5DB.h"

unsigned int cgxe_ArduinoTests_method_dispatcher(SimStruct* S, int_T method,
  void* data)
{
  if (ssGetChecksum0(S) == 3704831919 &&
      ssGetChecksum1(S) == 2360107975 &&
      ssGetChecksum2(S) == 1785260133 &&
      ssGetChecksum3(S) == 555529238) {
    method_dispatcher_ghzL9u6H4AUvnUT3cRQ5DB(S, method, data);
    return 1;
  }

  return 0;
}
