#if defined(__clang__)

#include "babble"

#include <pxr/usdImaging/usdImagingGL/engine.h>
#include <pxr/usdImaging/usdImagingGL/renderParams.h>
#include <pxr/imaging/hgiVulkan/hgi.h>
#include <pxr/imaging/hgiVulkan/device.h>
#include <pxr/imaging/hgiVulkan/instance.h>
#include <pxr/imaging/hgiVulkan/texture.h>

namespace bblext {
    void GLRenderParams_SetEnableLighting(PXR_NS::UsdImagingGLRenderParams& params, bool enableLighting) {
        params.enableLighting = enableLighting;
    }

    void GLRenderParams_SetCullStyle(PXR_NS::UsdImagingGLRenderParams& params, PXR_NS::UsdImagingGLCullStyle cullStyle) {
        params.cullStyle = cullStyle;
    }

    void GLRenderParams_SetColorCorrectionMode(PXR_NS::UsdImagingGLRenderParams& params, PXR_NS::TfToken colorCorrectionMode) {
        params.colorCorrectionMode = colorCorrectionMode;
    }

    PXR_NS::UsdImagingGLEngine * GLEngine_from_vulkan(PXR_NS::HgiVulkan& hgi_vulkan) {
        PXR_NS::Hgi* hgi = &hgi_vulkan;
        PXR_NS::HdDriver driver {PXR_NS::HgiTokens->renderDriver, PXR_NS::VtValue(hgi)};
        return new PXR_NS::UsdImagingGLEngine(driver);
    }

    uint64_t HgiVulkanInstance_GetVulkanInstance(PXR_NS::HgiVulkanInstance& instance) {
        return (uint64_t)instance.GetVulkanInstance();
    }

    uint64_t HgiVulkanDevice_GetVulkanDevice(PXR_NS::HgiVulkanDevice& device) {
        return (uint64_t)device.GetVulkanDevice();
    }

    uint64_t HgiVulkanDevice_GetVulkanPhysicalDevice(PXR_NS::HgiVulkanDevice& device) {
        return (uint64_t)device.GetVulkanPhysicalDevice();
    }

    uint64_t HgiVulkanTexture_GetImage(PXR_NS::HgiVulkanTexture& texture) {
        return (uint64_t)texture.GetImage();
    }

    PXR_NS::HgiVulkanTexture* get_vulkan_texture(PXR_NS::HgiTextureHandle& handle) {
        return static_cast<PXR_NS::HgiVulkanTexture*>(handle.Get());
    }
}

BBL_MODULE(usdImaging) {
    bbl::Class<PXR_NS::UsdImagingGLEngine>("GLEngine")
        .ctor(bbl::Class<PXR_NS::UsdImagingGLEngine>::Ctor<>(), "new")
        .m(&PXR_NS::UsdImagingGLEngine::SetRenderViewport)
        .m(&PXR_NS::UsdImagingGLEngine::SetCameraState)
        .m(&PXR_NS::UsdImagingGLEngine::Render)
        .m(&PXR_NS::UsdImagingGLEngine::SetRendererSetting)
        .m(&PXR_NS::UsdImagingGLEngine::SetRendererAov)
        .m(&PXR_NS::UsdImagingGLEngine::GetGPUEnabled)
        .m(&PXR_NS::UsdImagingGLEngine::GetCurrentRendererId)
        .m(&PXR_NS::UsdImagingGLEngine::SetRendererPlugin)
        .m(&PXR_NS::UsdImagingGLEngine::GetRendererPlugins)
        .m(&PXR_NS::UsdImagingGLEngine::GetRendererDisplayName)
        .m(&PXR_NS::UsdImagingGLEngine::SetColorCorrectionSettings)
        .m(&PXR_NS::UsdImagingGLEngine::TestIntersection)
        .m(&PXR_NS::UsdImagingGLEngine::SetEnablePresentation)
        .m(&PXR_NS::UsdImagingGLEngine::GetAovTexture)
    ;

    bbl::Class<PXR_NS::HgiTextureHandle>("HgiTextureHandle");

    bbl::Class<PXR_NS::HgiVulkanTexture>("HgiVulkanTexture")
    ;

    bbl::Class<PXR_NS::HgiVulkan>("HgiVulkan")
        .ctor(bbl::Class<PXR_NS::HgiVulkan>::Ctor<>(), "new")
        .m(&PXR_NS::HgiVulkan::GetVulkanInstance)
        .m(&PXR_NS::HgiVulkan::GetPrimaryDevice)
    ;

 bbl::Class<PXR_NS::HgiVulkanInstance>("HgiVulkanInstance")
    ;


 bbl::Class<PXR_NS::HgiVulkanDevice>("HgiVulkanDevice")
        .m(&PXR_NS::HgiVulkanDevice::GetVulkanDevice)
        .m(&PXR_NS::HgiVulkanDevice::GetVulkanPhysicalDevice)
        .m(&PXR_NS::HgiVulkanDevice::GetCommandQueue)
    ;


    bbl::Class<PXR_NS::UsdImagingGLRenderParams>("GLRenderParams")
        .ctor(bbl::Class<PXR_NS::UsdImagingGLRenderParams>::Ctor<>(), "new");

    bbl::Enum<PXR_NS::UsdImagingGLCullStyle>("GLCullStyle");

    bbl::fn(&bblext::GLRenderParams_SetEnableLighting);
    bbl::fn(&bblext::GLRenderParams_SetCullStyle);
    bbl::fn(&bblext::GLRenderParams_SetColorCorrectionMode);
    bbl::fn(&bblext::GLEngine_from_vulkan);
    bbl::fn(&bblext::HgiVulkanInstance_GetVulkanInstance);
    bbl::fn(&bblext::HgiVulkanDevice_GetVulkanDevice);
    bbl::fn(&bblext::HgiVulkanDevice_GetVulkanPhysicalDevice);

    bbl::fn(&bblext::get_vulkan_texture);
    bbl::fn(&bblext::HgiVulkanTexture_GetImage);
}


#endif
