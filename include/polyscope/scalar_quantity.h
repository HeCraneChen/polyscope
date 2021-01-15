#pragma once

#include "polyscope/render/engine.h"

namespace polyscope {

// Encapsulates logic which is common to all scalar quantities

template <typename QuantityT>
class ScalarQuantity {
public:
  ScalarQuantity(QuantityT& parent, const std::vector<double>& values, DataType dataType);

  // Build the ImGUI UIs for scalars
  void buildScalarUI();
  void buildScalarOptionsUI(); // called inside of an options menu

  // Add rules to rendering programs for scalars
  std::vector<std::string> addScalarRules(std::vector<std::string> rules);

  // Set uniforms in rendering programs for scalars
  void setScalarUniforms(render::ShaderProgram& p);

  // === Members
  QuantityT& quantity;
  std::vector<double> values;
  const DataType dataType;

  // === Get/set visualization parameters

  // The color map
  QuantityT* setColorMap(std::string val);
  std::string getColorMap();

  // Data limits mapped in to colormap
  QuantityT* setMapRange(std::pair<double, double> val);
  std::pair<double, double> getMapRange();
  QuantityT* resetMapRange(); // reset to full range

  // Isolines
  QuantityT* setIsolinesEnabled(bool newEnabled);
  bool getIsolinesEnabled();
  QuantityT* setIsolineWidth(double size, bool isRelative);
  double getIsolineWidth();


protected:
  // === Visualization parameters

  // Affine data maps and limits
  std::pair<float, float> vizRange; // TODO make these persistent
  std::pair<double, double> dataRange;
  Histogram hist;

  // Parameters
  PersistentValue<std::string> cMap;
  PersistentValue<bool> isolinesEnabled;
  PersistentValue<ScaledValue<float>> isolineWidth;
};

} // namespace polyscope


#include "polyscope/scalar_quantity.ipp"
