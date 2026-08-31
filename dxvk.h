#pragma once

#include <dxgi.h>
#include <d3d11_1.h>
#include <vulkan/vulkan.h>

typedef struct {
    PFN_vkGetInstanceProcAddr loader_proc;
    VkInstance instance;
    uint32_t extension_count;
    const char **extension_names;
} Vulkan_Instance_Info;

HRESULT DXVK_CreateDXGIFactory(Vulkan_Instance_Info *instance, REFIID riid, void **ppFactory);
VkSemaphore DXVK_ID3D11Fence_GetVkSemaphore(ID3D11Fence *fence);
HRESULT DXVK_IDXGIVkInteropDevice1_GetVulkanHandles(ID3D11Device1 *device, VkInstance *pInstance, VkPhysicalDevice *pPhysDev, VkDevice *pDevice);
HRESULT DXVK_IDXGIVkInteropDevice1_CreateTexture2DFromVkImage(ID3D11Device1 *device, const D3D11_TEXTURE2D_DESC1* pDesc, VkImage vkImage, ID3D11Texture2D **ppTexture2D);
