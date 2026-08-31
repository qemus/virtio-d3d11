#include <triton.h>
#include <vulkan/vulkan.h>

typedef struct {
    TRITON_RESOURCE base;
    VkDeviceMemory memory;
    VkImage image;
} VIRTIO_WDDM_Resource;

size_t APIENTRY virtio_wddm_calc_resource_size(D3D10DDI_HDEVICE hDevice, const D3D11DDIARG_CREATERESOURCE *pArgs);
size_t APIENTRY virtio_wddm_calc_opened_resource_size(D3D10DDI_HDEVICE hDevice, const D3D10DDIARG_OPENRESOURCE *pArgs);
void APIENTRY virtio_wddm_create_resource(D3D10DDI_HDEVICE hDevice, const D3D11DDIARG_CREATERESOURCE *pArgs, D3D10DDI_HRESOURCE hResource, D3D10DDI_HRTRESOURCE hRTResource);
void APIENTRY virtio_wddm_open_resource(D3D10DDI_HDEVICE hDevice, const D3D10DDIARG_OPENRESOURCE *pArgs, D3D10DDI_HRESOURCE hResource, D3D10DDI_HRTRESOURCE hRTResource);
void APIENTRY virtio_wddm_destroy_resource(D3D10DDI_HDEVICE hDevice, D3D10DDI_HRESOURCE hResource);
void virtio_wddm_save_texture_to_ppm(VIRTIO_WDDM_Device *device, VIRTIO_WDDM_Resource *resource, const char *filename);
