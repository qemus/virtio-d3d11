#ifndef VULKAN_D3DDDI_H_
#define VULKAN_D3DDDI_H_ 1

#ifdef __cplusplus
extern "C" {
#endif

#define VK_STRUCTURE_TYPE_D3DDDI_CALLBACKS       ((VkStructureType)4281808695u)
#define VK_STRUCTURE_TYPE_D3DDDI_CREATE_RESOURCE ((VkStructureType)4281808696u)
#define VK_STRUCTURE_TYPE_D3DDDI_OPEN_RESOURCE   ((VkStructureType)4281808697u)

#ifdef D3DDDI_INCLUDE_WDK_TYPEDEFS
typedef struct D3D10DDIARG_OPENRESOURCE D3D10DDIARG_OPENRESOURCE;
typedef struct D3D10DDIARG_CREATERESOURCE D3D10DDIARG_CREATERESOURCE;
typedef struct D3D11DDIARG_CREATERESOURCE D3D11DDIARG_CREATERESOURCE;
#endif

typedef struct {
    VkStructureType sType;
    void *pNext;

    LUID AdapterLuid;

    HANDLE                          hRTAdapter;         // in: Runtime handle
    HANDLE                          hRTDevice;          // in: Runtime handle
    const D3DDDI_ADAPTERCALLBACKS  *pAdapterCallbacks;  // in: Pointer to runtime callbacks that invoke kernel
    const D3DDDI_DEVICECALLBACKS   *pKTCallbacks;       // in: Pointer to runtime callbacks that invoke kernel
    const DXGI_DDI_BASE_CALLBACKS  *pDXGIBaseCallbacks; // in: The driver should record this pointer for later use

    HANDLE                                    hRTCoreLayer;   // in:  CoreLayer handle
    const D3D11DDI_CORELAYER_DEVICECALLBACKS* p11UMCallbacks; // in:  callbacks that stay in usermode
} VkD3DDDICallbacks;

typedef struct {
    VkStructureType sType;
    void *pNext;
    HANDLE hRTResource;
    union {
        const D3D10DDIARG_CREATERESOURCE *pCreateResource10;
        const D3D11DDIARG_CREATERESOURCE *pCreateResource11;
    };
} VkD3DDDICreateResource;

typedef struct {
    VkStructureType sType;
    void *pNext;
    HANDLE hRTResource;
    const D3D10DDIARG_OPENRESOURCE *pOpenResource;
    const void *pResourceInfo; /* VIRTIO_WDDM_ResourceInfo */
} VkD3DDDIOpenResource;

#define VK_STRUCTURE_TYPE_D3DDDI_CALLBACKS_cast       VkD3DDDICallbacks
#define VK_STRUCTURE_TYPE_D3DDDI_CREATE_RESOURCE_cast VkD3DDDICreateResource
#define VK_STRUCTURE_TYPE_D3DDDI_OPEN_RESOURCE_cast   VkD3DDDIOpenResource

#ifdef __cplusplus
}
#endif

#endif
