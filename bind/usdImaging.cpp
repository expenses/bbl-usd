#if defined(__clang__)

#include "babble"

#include <pxr/usdImaging/usdImagingGL/engine.h>
#include <pxr/usdImaging/usdImagingGL/renderParams.h>

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
    ;

    bbl::Class<PXR_NS::UsdImagingGLRenderParams>("GLRenderParams")
        .ctor(bbl::Class<PXR_NS::UsdImagingGLRenderParams>::Ctor<>(), "new");

    bbl::Enum<PXR_NS::UsdImagingGLCullStyle>("GLCullStyle");

    bbl::fn(&bblext::GLRenderParams_SetEnableLighting);
    bbl::fn(&bblext::GLRenderParams_SetCullStyle);
    bbl::fn(&bblext::GLRenderParams_SetColorCorrectionMode);
}


#endif
