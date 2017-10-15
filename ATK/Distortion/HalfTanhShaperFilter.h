/**
 * \file HalfTanhShaperFilter.h
 */

#ifndef ATK_DISTORTION_HALFTANHSHAPERFILTER_H
#define ATK_DISTORTION_HALFTANHSHAPERFILTER_H

#include <ATK/Core/TypedBaseFilter.h>
#include "config.h"

namespace ATK
{
  /// Negative half of the signal tanh mapper
  template<typename DataType_>
  class ATK_DISTORTION_EXPORT HalfTanhShaperFilter final : public TypedBaseFilter<DataType_>
  {
  protected:
    /// Simplify parent calls
    typedef TypedBaseFilter<DataType_> Parent;
    using typename Parent::DataType;
    using Parent::converted_inputs;
    using Parent::outputs;
    using Parent::nb_input_ports;
    using Parent::nb_output_ports;
    using Parent::input_sampling_rate;
    using Parent::output_sampling_rate;

  public:
    /*!
    * @brief Constructor
    * @param nb_channels is the number of input and output channels
    */
    HalfTanhShaperFilter(std::size_t nb_channels = 1);
    /// Destructor
    ~HalfTanhShaperFilter();
    
    void set_coefficient(DataType coeff);
    DataType_ get_coefficient() const;
    
  protected:
    virtual void process_impl(std::size_t size) const final;
  private:
    DataType coeff;
  };
}

#endif
