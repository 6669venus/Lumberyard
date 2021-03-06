/*
* All or portions of this file Copyright (c) Amazon.com, Inc. or its affiliates or
* its licensors.
*
* For complete copyright and license terms please see the LICENSE at the root of this
* distribution (the "License"). All use of this software is governed by the License,
* or, if provided, by the license below or the license accompanying this file. Do not
* remove or modify any license notices. This file is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*
*/

#include "StdAfx.h"

#include "LmbrCentralEditor.h"

// Metrics
#include "Metrics/LyEditorMetricsSystemComponent.h"

#include "Animation/EditorAttachmentComponent.h"
#include "Audio/EditorAudioAreaEnvironmentComponent.h"
#include "Audio/EditorAudioEnvironmentComponent.h"
#include "Audio/EditorAudioListenerComponent.h"
#include "Audio/EditorAudioRtpcComponent.h"
#include "Audio/EditorAudioSwitchComponent.h"
#include "Audio/EditorAudioTriggerComponent.h"
#include "Cinematics/EditorSequenceComponent.h"
#include "Cinematics/EditorSequenceAgentComponent.h"
#include "Physics/EditorConstraintComponent.h"
#include "Physics/EditorRigidPhysicsComponent.h"
#include "Physics/EditorStaticPhysicsComponent.h"
#include "Rendering/EditorDecalComponent.h"
#include "Scripting/EditorFlowGraphComponent.h"
#include "Rendering/EditorLensFlareComponent.h"
#include "Rendering/EditorLightComponent.h"
#include "Rendering/EditorPointLightComponent.h"
#include "Rendering/EditorAreaLightComponent.h"
#include "Rendering/EditorProjectorLightComponent.h"
#include "Rendering/EditorEnvProbeComponent.h"
#include "Rendering/EditorStaticMeshComponent.h"
#include "Rendering/EditorSkinnedMeshComponent.h"
#include "Rendering/EditorParticleComponent.h"
#include "Animation/EditorSimpleAnimationComponent.h"
#include "Animation/EditorMannequinScopeComponent.h"
#include "Animation/EditorMannequinComponent.h"
#include "Scripting/EditorLookAtComponent.h"
#include "Scripting/EditorTagComponent.h"
#include "Scripting/EditorTriggerAreaComponent.h"

#include "Shape/EditorBoxShapeComponent.h"
#include "Shape/EditorSphereShapeComponent.h"
#include "Shape/EditorCylinderShapeComponent.h"
#include "Shape/EditorCapsuleShapeComponent.h"
#include "Editor/EditorCommentComponent.h"

#include "Shape/EditorCompoundShapeComponent.h"

#include <AzFramework/Metrics/MetricsPlainTextNameRegistration.h>
#include <AzToolsFramework/ToolsComponents/EditorSelectionAccentSystemComponent.h>

namespace LmbrCentral
{
    LmbrCentralEditorModule::LmbrCentralEditorModule()
        : LmbrCentralModule()
    {
        m_descriptors.insert(m_descriptors.end(), {
            EditorAttachmentComponent::CreateDescriptor(),
            EditorAudioAreaEnvironmentComponent::CreateDescriptor(),
            EditorAudioEnvironmentComponent::CreateDescriptor(),
            EditorAudioListenerComponent::CreateDescriptor(),
            EditorAudioRtpcComponent::CreateDescriptor(),
            EditorAudioSwitchComponent::CreateDescriptor(),
            EditorAudioTriggerComponent::CreateDescriptor(),
            EditorConstraintComponent::CreateDescriptor(),
            EditorDecalComponent::CreateDescriptor(),
            EditorFlowGraphComponent::CreateDescriptor(),
            EditorLensFlareComponent::CreateDescriptor(),
            EditorLightComponent::CreateDescriptor(),
            EditorPointLightComponent::CreateDescriptor(),
            EditorAreaLightComponent::CreateDescriptor(),
            EditorProjectorLightComponent::CreateDescriptor(),
            EditorEnvProbeComponent::CreateDescriptor(),
            EditorStaticMeshComponent::CreateDescriptor(),
            EditorSkinnedMeshComponent::CreateDescriptor(),
            EditorParticleComponent::CreateDescriptor(),
            EditorSimpleAnimationComponent::CreateDescriptor(),
            EditorTagComponent::CreateDescriptor(),
            EditorTriggerAreaComponent::CreateDescriptor(),
            EditorMannequinScopeComponent::CreateDescriptor(),
            EditorMannequinComponent::CreateDescriptor(),
            EditorSphereShapeComponent::CreateDescriptor(),
            EditorRigidPhysicsComponent::CreateDescriptor(),
            EditorStaticPhysicsComponent::CreateDescriptor(),
            EditorBoxShapeComponent::CreateDescriptor(),
            EditorLookAtComponent::CreateDescriptor(),
            EditorCylinderShapeComponent::CreateDescriptor(),
            EditorCapsuleShapeComponent::CreateDescriptor(),
            EditorCompoundShapeComponent::CreateDescriptor(),
            EditorCommentComponent::CreateDescriptor(),
            #ifdef METRICS_SYSTEM_COMPONENT_ENABLED
            LyEditorMetrics::LyEditorMetricsSystemComponent::CreateDescriptor(),
            #endif // #ifdef METRICS_SYSTEM_COMPONENT_ENABLED
            EditorSequenceComponent::CreateDescriptor(),
            EditorSequenceAgentComponent::CreateDescriptor()
        });

        // This is internal Amazon code, so register it's components for metrics tracking, otherwise the name of the component won't get sent back.
        AZStd::vector<AZ::Uuid> typeIds;
        typeIds.reserve(m_descriptors.size());
        for (AZ::ComponentDescriptor* descriptor : m_descriptors)
        {
            typeIds.emplace_back(descriptor->GetUuid());
        }
        EBUS_EVENT(AzFramework::MetricsPlainTextNameRegistrationBus, RegisterForNameSending, typeIds);
    }

    AZ::ComponentTypeList LmbrCentralEditorModule::GetRequiredSystemComponents() const
    {
        AZ::ComponentTypeList requiredComponents = LmbrCentralModule::GetRequiredSystemComponents();

        #ifdef METRICS_SYSTEM_COMPONENT_ENABLED
        requiredComponents.push_back(azrtti_typeid<LyEditorMetrics::LyEditorMetricsSystemComponent>());
        #endif // #ifdef METRICS_SYSTEM_COMPONENT_ENABLED
        requiredComponents.push_back(azrtti_typeid<AzToolsFramework::Components::EditorSelectionAccentSystemComponent>());

        return requiredComponents;
    }

} // namespace LmbrCentral

AZ_DECLARE_MODULE_CLASS(LmbrCentralEditor, LmbrCentral::LmbrCentralEditorModule)