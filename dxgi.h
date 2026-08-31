#pragma once

#include <triton.h>

HRESULT APIENTRY virtio_wddm_present(DXGI_DDI_ARG_PRESENT *pArgs);
HRESULT APIENTRY virtio_wddm_get_gamma_caps(DXGI_DDI_ARG_GET_GAMMA_CONTROL_CAPS *pArgs);
HRESULT APIENTRY virtio_wddm_set_display_mode(DXGI_DDI_ARG_SETDISPLAYMODE *pArgs);
HRESULT APIENTRY virtio_wddm_set_resource_priority(DXGI_DDI_ARG_SETRESOURCEPRIORITY *pArgs);
HRESULT APIENTRY virtio_wddm_query_resource_residency(DXGI_DDI_ARG_QUERYRESOURCERESIDENCY *pArgs);
HRESULT APIENTRY virtio_wddm_rotate_resource_identities(DXGI_DDI_ARG_ROTATE_RESOURCE_IDENTITIES *pArgs);
HRESULT APIENTRY virtio_wddm_blt(DXGI_DDI_ARG_BLT *pArgs);
HRESULT APIENTRY virtio_wddm_resolve_shared_resource(DXGI_DDI_ARG_RESOLVESHAREDRESOURCE *pArgs);
HRESULT APIENTRY virtio_wddm_blt1(DXGI_DDI_ARG_BLT1 *pArgs);
HRESULT APIENTRY virtio_wddm_offer_resources(DXGI_DDI_ARG_OFFERRESOURCES *pArgs);
HRESULT APIENTRY virtio_wddm_reclaim_resources(DXGI_DDI_ARG_RECLAIMRESOURCES *pArgs);
/*
HRESULT APIENTRY virtio_wddm_get_multiplane_overlay_caps(DXGI_DDI_ARG_GETMULTIPLANEOVERLAYCAPS *pArgs);
HRESULT APIENTRY virtio_wddm_get_multiplane_overlay_filter_range(void *pArgs);
HRESULT APIENTRY virtio_wddm_check_multiplane_overlay_support(DXGI_DDI_ARG_CHECKMULTIPLANEOVERLAYSUPPORT *pArgs);
HRESULT APIENTRY virtio_wddm_present_multiplane_overlay(DXGI_DDI_ARG_PRESENTMULTIPLANEOVERLAY *pArgs);
*/
