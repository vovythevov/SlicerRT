/*==============================================================================

  Copyright (c) Radiation Medicine Program, University Health Network,
  Princess Margaret Hospital, Toronto, ON, Canada. All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  This file was originally developed by Kevin Wang, Princess Margaret Cancer Centre 
  and was supported by Cancer Care Ontario (CCO)'s ACRU program 
  with funds provided by the Ontario Ministry of Health and Long-Term Care
  and Ontario Consortium for Adaptive Interventions in Radiation Oncology (OCAIRO).

==============================================================================*/

///  vtkSliceRTScalarBarActor - slicer vtk class for adding color names in scalarbar
///
/// This class enhances the vtkScalarBarActor class by adding color names 
/// in the label display.

#ifndef __vtkSlicerRTScalarBarActor_h
#define __vtkSlicerRTScalarBarActor_h

// VTK includes
#include "vtkScalarBarActor.h"
#include "vtkStringArray.h"
#include "vtkVersion.h"

// MRMLLogic includes
#include "vtkSlicerIsodoseModuleWidgetsExport.h"

/// \ingroup SlicerRt_QtModules_Isodose
class VTK_SLICER_ISODOSE_LOGIC_EXPORT vtkSlicerRTScalarBarActor 
  : public vtkScalarBarActor
{
public:
  // The usual VTK class functions
  static vtkSlicerRTScalarBarActor *New();
  vtkTypeMacro(vtkSlicerRTScalarBarActor,vtkScalarBarActor);
  void PrintSelf(ostream& os, vtkIndent indent);

#if (VTK_MAJOR_VERSION <= 5)
  /// Get for the flag on using color names as label
  vtkGetMacro(UseColorNameAsLabel, int);
  /// Set for the flag on using color names as label
  vtkSetMacro(UseColorNameAsLabel, int);
  /// Get/Set for the flag on using color names as label
  vtkBooleanMacro(UseColorNameAsLabel, int);

  /// Get color names array
  vtkGetObjectMacro(ColorNames, vtkStringArray);

  /// Set the ith color name.
  int SetColorName(int ind, const char *name);

protected:
  /// Set color names array
  vtkSetObjectMacro(ColorNames, vtkStringArray);

#else
  /// Get for the flag on using VTK6 annotation as label
  vtkGetMacro(UseAnnotationAsLabel, int);
  /// Set for the flag on using VTK6 annotation as label
  vtkSetMacro(UseAnnotationAsLabel, int);
  /// Get/Set for the flag on using VTK6 annotation as label
  vtkBooleanMacro(UseAnnotationAsLabel, int);

  // Description:
  // Determine the size and placement of any tick marks to be rendered.
  //
  // This method must set this->P->TickBox.
  // It may depend on layout performed by ComputeScalarBarLength.
  //
  // The default implementation creates exactly this->NumberOfLabels
  // tick marks, uniformly spaced on a linear or logarithmic scale.
  virtual void LayoutTicks();
#endif

protected:
  vtkSlicerRTScalarBarActor();
  ~vtkSlicerRTScalarBarActor();

#if (VTK_MAJOR_VERSION <= 5)
  /// overloaded virtual function that adds the color name as label
  virtual void AllocateAndSizeLabels(int *labelSize, int *size,
                                     vtkViewport *viewport, double *range);

  /// A vector of names for the color table elements
  vtkStringArray* ColorNames;

  /// flag for setting color name as label
  int UseColorNameAsLabel;
#else
  /// flag for setting color name as label
  int UseAnnotationAsLabel;
#endif

private:
  vtkSlicerRTScalarBarActor(const vtkSlicerRTScalarBarActor&);  // Not implemented.
  void operator=(const vtkSlicerRTScalarBarActor&);  // Not implemented.
};

#endif

