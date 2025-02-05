/*==============================================================================

  Copyright (c) Laboratory for Percutaneous Surgery (PerkLab)
  Queen's University, Kingston, ON, Canada. All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  This file was originally developed by Csaba Pinter, PerkLab, Queen's University
  and was supported through the Applied Cancer Research Unit program of Cancer Care
  Ontario with funds provided by the Ontario Ministry of Health and Long-Term Care

==============================================================================*/

// .NAME vtkSlicerBeamsModuleLogic - slicer logic class for volumes manipulation
// .SECTION Description
// This class manages the logic associated with reading, saving,
// and changing propertied of the volumes


#ifndef __vtkSlicerBeamsModuleLogic_h
#define __vtkSlicerBeamsModuleLogic_h

// Slicer includes
#include "vtkSlicerModuleLogic.h"

// STD includes
#include "vtkSlicerBeamsModuleLogicExport.h"

class vtkTransform;
class vtkPolyData;
class vtkMRMLBeamsNode;

/// \ingroup SlicerRt_QtModules_Beams
class VTK_SLICER_BEAMS_LOGIC_EXPORT vtkSlicerBeamsModuleLogic :
  public vtkSlicerModuleLogic
{
public:
  static vtkSlicerBeamsModuleLogic *New();
  vtkTypeMacro(vtkSlicerBeamsModuleLogic,vtkSlicerModuleLogic);
  void PrintSelf(ostream& os, vtkIndent indent);

  /// Create beam geometry model from isocenter and source fiducials
  /// \param errorMessage Error message if any. If empty, then there have been no errors in course of the computation
  /// \return Error message, empty string if no error
  std::string CreateBeamModel();

  /// Create beam vtkpolydata from beam parameters
  /// \param x/y jaw positions and SAD
  /// \return polydata, null if it fails to create polydata
  vtkSmartPointer<vtkPolyData> CreateBeamPolyData(double, double, double, double, double);

public:
  /// Set and observe dose accumulation parameter node 
  void SetAndObserveBeamsNode(vtkMRMLBeamsNode* node);

  /// Get dose accumulation parameter node 
  vtkGetObjectMacro(BeamsNode, vtkMRMLBeamsNode);

protected:
  vtkSlicerBeamsModuleLogic();
  virtual ~vtkSlicerBeamsModuleLogic();

  virtual void SetMRMLSceneInternal(vtkMRMLScene* newScene);

  /// Register MRML Node classes to Scene. Gets called automatically when the MRMLScene is attached to this logic class.
  virtual void RegisterNodes();

  virtual void UpdateFromMRMLScene();
  virtual void OnMRMLSceneNodeAdded(vtkMRMLNode* node);
  virtual void OnMRMLSceneNodeRemoved(vtkMRMLNode* node);
  virtual void OnMRMLSceneEndImport();
  virtual void OnMRMLSceneEndClose();

private:
  vtkSlicerBeamsModuleLogic(const vtkSlicerBeamsModuleLogic&); // Not implemented
  void operator=(const vtkSlicerBeamsModuleLogic&);               // Not implemented

protected:
  /// Parameter set MRML node
  vtkMRMLBeamsNode* BeamsNode;
};

#endif

