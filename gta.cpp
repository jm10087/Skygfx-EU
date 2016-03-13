#include "skygfx.h"

RsGlobalType *RsGlobal = (RsGlobalType*)0xC17040;
IDirect3DDevice9 *&d3d9device = *(IDirect3DDevice9**)0xC97C28;
RwCamera *&Camera = *(RwCamera**)0xC1703C;
RpLight *&pAmbient = *(RpLight**)0xC886E8;
RpLight *&pDirect = *(RpLight**)0xC886EC;
RpLight **pExtraDirectionals = (RpLight**)0xC886F0;
int &NumExtraDirLightsInWorld = *(int*)0xC88708;
D3DLIGHT9 &gCarEnvMapLight = *(D3DLIGHT9*)0xC02CB0;

char &doRadiosity = *(char*)0xC402CC;

RwTexture *&gpWhiteTexture = *(RwTexture**)0xB4E3EC;
RwBool reflTexDone;
RwRaster *reflTex;

void **rwengine = *(void***)0x58FFC0;
RwInt32 &CCustomCarEnvMapPipeline__ms_envMapPluginOffset = *(RwInt32*)0x8D12C4;
RwInt32 &CCustomCarEnvMapPipeline__ms_envMapAtmPluginOffset = *(RwInt32*)0x8D12C8;
RwInt32 &CCustomCarEnvMapPipeline__ms_specularMapPluginOffset = *(RwInt32*)0x8D12CC;
RwReal &CCustomCarEnvMapPipeline__m_EnvMapLightingMult = *(RwReal*)0x8D12D0;
RwInt32 &CCustomBuildingDNPipeline__ms_extraVertColourPluginOffset = *(RwInt32*)0x8D12BC;
RwReal &CCustomBuildingDNPipeline__m_fDNBalanceParam = *(float*)0x8D12C0;
int &dword_C02C20 = *(int*)0xC02C20;
int &dword_C9BC60 = *(int*)0xC9BC60;
RxPipeline *&skinPipe = *(RxPipeline**)0xC978C4;
RxPipeline *&CCustomCarEnvMapPipeline__ObjPipeline = *(RxPipeline**)0xC02D24;

int &CPostEffects__m_RadiosityFilterPasses = *(int*)0x8D510C;
int &CPostEffects__m_RadiosityRenderPasses = *(int*)0x8D5110;
int &CPostEffects__m_RadiosityIntensityLimit = *(int*)0x8D5114;
int &CPostEffects__m_RadiosityIntensity = *(int*)0x8D5118;
int &CPostEffects__m_RadiosityFilterUCorrection = *(int*)0x8D511C;
int &CPostEffects__m_RadiosityFilterVCorrection = *(int*)0x8D5120;

WRAPPER RwMatrix *RwFrameGetLTM(RwFrame * frame) { EAXJMP(0x7F09D0); } //different
WRAPPER RpMaterial *RpMaterialSetTexture(RpMaterial *mat, RwTexture *tex) { EAXJMP(0x74DC10); } //different
WRAPPER RwRaster *RwRasterCreate(RwInt32 width, RwInt32 height, RwInt32 depth, RwInt32 flags) { EAXJMP(0x7FB270); } //different
WRAPPER RwBool RwRasterDestroy(RwRaster *raster) { EAXJMP(0x7FB060); } //different
WRAPPER RwRaster *RwRasterPushContext(RwRaster *raster) { EAXJMP(0x7FB0A0); } //different
WRAPPER RwRaster *RwRasterPopContext(void) { EAXJMP(0x7FB150); } //different
WRAPPER RwRaster *RwRasterRenderScaled(RwRaster *raster, RwRect *rect) { EAXJMP(0x7FAEC0); } //different
WRAPPER RwRaster *RwRasterRenderFast(RwRaster *raster, RwInt32 x, RwInt32 y) { EAXJMP(0x7FAF90); } //different
WRAPPER RwUInt8 *RwRasterLock(RwRaster*, RwUInt8, RwInt32) { EAXJMP(0x7FB310); } //different
WRAPPER RwRaster *RwRasterUnlock(RwRaster*) { EAXJMP(0x7FAF00); } //different
WRAPPER RwCamera *RwCameraBeginUpdate(RwCamera *camera) { EAXJMP(0x7EE1D0); } //different
WRAPPER RwCamera *RwCameraEndUpdate(RwCamera *camera) { EAXJMP(0x7EE1C0); } //different
WRAPPER RwTexture *RwTextureCreate(RwRaster*) { EAXJMP(0x7F3800); } //different

WRAPPER RwInt32 RpMaterialRegisterPlugin(RwInt32, RwUInt32, RwPluginObjectConstructor,
	RwPluginObjectDestructor, RwPluginObjectCopy) { EAXJMP(0x74DC40); } //different
WRAPPER RwInt32 RpMaterialSetStreamRightsCallBack(RwUInt32, RwPluginDataChunkRightsCallBack) { EAXJMP(0x74DCC0); } //different
WRAPPER RwInt32 RpAtomicRegisterPlugin(RwInt32, RwUInt32, RwPluginObjectConstructor,
	RwPluginObjectDestructor, RwPluginObjectCopy) { EAXJMP(0x74BDF0); } //different
WRAPPER RwInt32 RpAtomicSetStreamRightsCallBack(RwUInt32, RwPluginDataChunkRightsCallBack) { EAXJMP(0x74BEA0); } //different


WRAPPER RpMatFXMaterialFlags RpMatFXMaterialGetEffects(const RpMaterial*) { EAXJMP(0x812180); } //different
WRAPPER const RpMaterial *RpMatFXMaterialGetUVTransformMatrices(const RpMaterial*, RwMatrix**, RwMatrix**) { EAXJMP(0x812A90); } //different

WRAPPER RwBool RwD3D9CreatePixelShader(const RwUInt32 *function, void **shader) { EAXJMP(0x7FAD00); } //different
WRAPPER RwBool RwD3D9CreateVertexShader(const RwUInt32 *function, void **shader) { EAXJMP(0x7FACA0); } //different
WRAPPER void _rwD3D9SetPixelShaderConstant(RwUInt32 i, const void *data, RwUInt32 size) { EAXJMP(0x7FAD40); } //different
WRAPPER void _rwD3D9VSSetActiveWorldMatrix(const RwMatrix *worldMatrix) { EAXJMP(0x7646A0); } //different
WRAPPER void _rwD3D9VSGetInverseWorldMatrix(void *inverseWorldMatrix) { EAXJMP(0x764800); } //different
WRAPPER void RwD3D9GetRenderState(RwUInt32 state, void *value) { EAXJMP(0x7FC360); } //different
WRAPPER void RwD3D9SetRenderState(RwUInt32 state, RwUInt32 value) { EAXJMP(0x7FC310); } //different
WRAPPER RwBool RwD3D9SetTexture(RwTexture *texture, RwUInt32 stage) { EAXJMP(0x7FDEB0); } //different
WRAPPER void RwD3D9SetTextureStageState(RwUInt32 stage, RwUInt32 type, RwUInt32 value) { EAXJMP(0x7FC380); } //different
WRAPPER RwBool RwD3D9SetSurfaceProperties(const RwSurfaceProperties *surfaceProps, const RwRGBA *color, RwUInt32 flags) { EAXJMP(0x7FC510); } //different
WRAPPER void RwD3D9GetTransform(RwUInt32 state, void *matrix) { EAXJMP(0x7FA530); } //different
WRAPPER RwBool RwD3D9SetTransform(RwUInt32 state, const void *matrix) { EAXJMP(0x7FA3D0); } //different
WRAPPER void _rwD3D9SetVertexShaderConstant(RwUInt32 registerAddress, const void *constantData, RwUInt32  constantCount) { EAXJMP(0x7FACE0); } //different
WRAPPER void _rwD3D9SetVertexShader(void *shader) { EAXJMP(0x7F9FF0); } //different
WRAPPER void _rwD3D9SetPixelShader(void *shader) { EAXJMP(0x7FA030); } //different
WRAPPER void _rwD3D9SetIndices(void *indexBuffer) { EAXJMP(0x7FA200); } //different
WRAPPER void _rwD3D9SetStreams(const RxD3D9VertexStream *streams, RwBool useOffsets) { EAXJMP(0x7FA0D0); } //different
WRAPPER void _rwD3D9SetVertexDeclaration(void *vertexDeclaration) { EAXJMP(0x7F9FB0); } //different
WRAPPER void _rwD3D9DrawIndexedPrimitive(RwUInt32 primitiveType, RwInt32 baseVertexIndex, RwUInt32 minIndex,
		RwUInt32 numVertices, RwUInt32 startIndex, RwUInt32 primitiveCount) { EAXJMP(0x7FA360); } //different
WRAPPER void _rwD3D9DrawPrimitive(RwUInt32 primitiveType, RwUInt32 startVertex, RwUInt32 primitiveCount) { EAXJMP(0x7FA3A0); } //different
WRAPPER void _rwD3D9DrawIndexedPrimitiveUP(RwUInt32 primitiveType, RwUInt32 minIndex, RwUInt32 numVertices, RwUInt32 primitiveCount,
	const void *indexData, const void *vertexStreamZeroData, RwUInt32 VertexStreamZeroStride) { EAXJMP(0x7FA230); } //different
WRAPPER RwBool RwD3D9SetLight(RwInt32 index, const void *light) { EAXJMP(0x7FA6A0); } //different
WRAPPER RwBool RwD3D9EnableLight(RwInt32 index, RwBool enable) { EAXJMP(0x7FA8A0); } //different
WRAPPER RwBool RwD3D9CreateVertexDeclaration(const void *elements, void **vertexdeclaration) { EAXJMP(0x7FAA70); } //different
WRAPPER void RwD3D9DestroyVertexBuffer(RwUInt32 stride, RwUInt32 size, void *vertexBuffer, RwUInt32 offset) { EAXJMP(0x7F56E0); } //different
WRAPPER RwBool RwD3D9CreateVertexBuffer(RwUInt32 stride, RwUInt32 size, void **vertexBuffer, RwUInt32 *offset) { EAXJMP(0x7F5540); } //different
WRAPPER RwUInt32 _rpD3D9VertexDeclarationInstV3d(RwUInt32 type, RwUInt8 *mem, const RwV3d *src,
		RwInt32 numVerts, RwUInt32 stride) { EAXJMP(0x752B20) }; //different
WRAPPER RwUInt32 _rpD3D9VertexDeclarationInstV2d(RwUInt32 type, RwUInt8 *mem, const RwV2d *src,
		RwInt32 numVerts, RwUInt32 stride) { EAXJMP(0x754530) }; //different
WRAPPER RwBool _rpD3D9VertexDeclarationInstColor(RwUInt8 *mem, const RwRGBA *color, RwInt32 numVerts, RwUInt32 stride) { EAXJMP(0x754B30); }; //different
WRAPPER RwBool RwD3D9SetRenderTarget(RwUInt32 index, RwRaster *raster) { EAXJMP(0x7F9ED0); }; //different

WRAPPER void _rxPipelineDestroy(RxPipeline * Pipeline) { EAXJMP(0x805860); } //different
WRAPPER RxPipeline *RxPipelineCreate(void) { EAXJMP(0x8057F0); } //different
WRAPPER RxPipeline *RxPipelineExecute(RxPipeline *pipeline, void *data, RwBool heapReset) { EAXJMP(0x805750); }; //different
WRAPPER RxLockedPipe *RxPipelineLock(RxPipeline *pipeline) { EAXJMP(0x8069D0); } //different
WRAPPER RxPipeline *RxLockedPipeUnlock(RxLockedPipe *pipeline) { EAXJMP(0x805F80); } //different
WRAPPER RxNodeDefinition *RxNodeDefinitionGetD3D9AtomicAllInOne(void) { EAXJMP(0x758330); } //different
WRAPPER RxPipelineNode *RxPipelineFindNodeByName(RxPipeline *pipeline, const RwChar *name, RxPipelineNode *start, RwInt32 *nodeIndex) { EAXJMP(0x806B70); } //different
WRAPPER RxLockedPipe *RxLockedPipeAddFragment(RxLockedPipe *pipeline, RwUInt32 *firstIndex, RxNodeDefinition *nodeDef0, ...) { EAXJMP(0x806C20); } //different
WRAPPER RxD3D9AllInOneInstanceCallBack RxD3D9AllInOneGetInstanceCallBack(RxPipelineNode *node) { EAXJMP(0x7573E0) }; //different
WRAPPER RxD3D9AllInOneReinstanceCallBack RxD3D9AllInOneGetReinstanceCallBack(RxPipelineNode *node) { EAXJMP(0x757400) }; //different
WRAPPER void RxD3D9AllInOneSetInstanceCallBack(RxPipelineNode *node, RxD3D9AllInOneInstanceCallBack callback) { EAXJMP(0x7573D0) }; //different
WRAPPER void RxD3D9AllInOneSetReinstanceCallBack(RxPipelineNode *node, RxD3D9AllInOneReinstanceCallBack callback) { EAXJMP(0x7573F0) }; //different
WRAPPER void RxD3D9AllInOneSetRenderCallBack(RxPipelineNode *node, RxD3D9AllInOneRenderCallBack callback) { EAXJMP(0x757430) }; //different

WRAPPER RwBool DNInstance(void *object, RxD3D9ResEntryHeader *resEntryHeader, RwBool reinstance) { EAXJMP(0x5D5FE0) };
WRAPPER RwBool D3D9RestoreSurfaceProperties(void) { EAXJMP(0x5DAAC0); }
WRAPPER RwBool D3D9SetRenderMaterialProperties(RwSurfaceProperties*, RwRGBA *color,
		RwUInt32 flags, RwReal specularLighting, RwReal specularPower) { EAXJMP(0x5DA790); };

WRAPPER RwUInt16 CVisibilityPlugins__GetAtomicId(RpAtomic *atomic) { EAXJMP(0x732370); }

WRAPPER RpAtomic *CCustomCarEnvMapPipeline__CustomPipeAtomicSetup(RpAtomic *atomic) { EAXJMP(0x5DA610); }
WRAPPER char *GetFrameNodeName(RwFrame *frame) { EAXJMP(0x72FB30); }
WRAPPER void SetPipelineID(RpAtomic*, unsigned int it) { EAXJMP(0x72FC50); }
WRAPPER RpAtomic *AtomicDefaultRenderCallBack(RpAtomic*) { EAXJMP(0x749210); }; //different
WRAPPER void CCustomCarEnvMapPipeline__CustomPipeRenderCB_exe(RwResEntry *repEntry, void *object, RwUInt8 type, RwUInt32 flags) { EAXJMP(0x5D9900) };
WRAPPER void GTAfree(void *data) { EAXJMP(0x82417F); } //different
