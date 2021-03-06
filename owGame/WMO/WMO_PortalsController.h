#pragma once

#include "WMO_Headers.h"

// FORWARD BEGIN
class CWMO_Base_Instance;
// FORWARD END

#ifdef USE_WMO_PORTALS_CULLING

class CWMO_PortalsController
{
public:
	CWMO_PortalsController();
    virtual ~CWMO_PortalsController();
	
	void Update(const CWMO_Base_Instance* SceneNodeInstance, const ICameraComponent3D* _camera);
	bool Recur(const CWMO_Base_Instance* SceneNodeInstance, const std::shared_ptr<IPortalRoom>& Room, const Frustum& CameraFrustum, const glm::vec3& _InvWorldCamera, const Frustum& _frustum, bool _isFirstIteration);
};

#endif
