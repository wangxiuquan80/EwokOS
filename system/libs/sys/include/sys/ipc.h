#ifndef IPC_H
#define IPC_H

#include <proto.h>
#include <_types.h>

#define IPC_SAFE_CMD_BASE 0x0FFFF

typedef void (*ipc_handle_t)(int from_pid, int call_id, void* p);
int      ipc_call(int to_pid, int call_id, const proto_t* ipkg, proto_t* opkg);
int      ipc_setup(ipc_handle_t handle, void* p, bool prefork);
int      ipc_set_return(const proto_t* ipkg);
proto_t* ipc_get_arg(void);
void     ipc_end(void);
void     ipc_ready(void);

#endif
