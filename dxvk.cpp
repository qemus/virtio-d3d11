#include <d3d11_fence.h>
#include <dxgi_interfaces.h>
#include <dxgi_factory.h>
#include <dxgi_adapter.h>

extern "C" {
#include "dxvk.h"

HRESULT DXVK_CreateDXGIFactory(Vulkan_Instance_Info *instance, REFIID riid, void **ppFactory) {
    try {
        dxvk::DxvkInstanceImportInfo args { };
        args.loaderProc = instance->loader_proc;
        args.instance = instance->instance;
        args.extensionCount = instance->extension_count;
        args.extensionNames = instance->extension_names;
        dxvk::Com<dxvk::DxgiFactory> factory = new dxvk::DxgiFactory(args, 0);
        HRESULT hr = factory->QueryInterface(riid, ppFactory);
        if (FAILED(hr)) return hr;
        return S_OK;
    } catch (const dxvk::DxvkError& e) {
        dxvk::Logger::err(e.message());
        return E_FAIL;
    }
}

VkSemaphore DXVK_ID3D11Fence_GetVkSemaphore(ID3D11Fence *fence) {
    dxvk::D3D11Fence *d3d11_fence = static_cast<dxvk::D3D11Fence *>(fence);
    if (!d3d11_fence) {
        return VK_NULL_HANDLE;
    }

    return d3d11_fence->GetFence()->handle();
}

HRESULT DXVK_IDXGIVkInteropDevice1_GetVulkanHandles(ID3D11Device1 *device, VkInstance *pInstance, VkPhysicalDevice *pPhysDev, VkDevice *pDevice) {
    IDXGIVkInteropDevice1 *interop_device;
    HRESULT hr = device->QueryInterface(__uuidof(IDXGIVkInteropDevice1), (void **) &interop_device);
    if (FAILED(hr)) {
        return hr;
    }

    interop_device->GetVulkanHandles(pInstance, pPhysDev, pDevice);
    interop_device->Release();
    return S_OK;
}

HRESULT DXVK_IDXGIVkInteropDevice1_CreateTexture2DFromVkImage(ID3D11Device1 *device, const D3D11_TEXTURE2D_DESC1* pDesc, VkImage vkImage, ID3D11Texture2D **ppTexture2D) {
    IDXGIVkInteropDevice1 *interop_device;
    HRESULT hr = device->QueryInterface(__uuidof(IDXGIVkInteropDevice1), (void **) &interop_device);
    if (FAILED(hr)) {
        return hr;
    }

    hr = interop_device->CreateTexture2DFromVkImage(pDesc, vkImage, ppTexture2D);
    interop_device->Release();
    return hr;
}

}
