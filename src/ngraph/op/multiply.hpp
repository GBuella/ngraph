//*****************************************************************************
// Copyright 2017-2019 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//*****************************************************************************

#pragma once

#include "ngraph/op/util/binary_elementwise_arithmetic.hpp"

namespace ngraph
{
    namespace op
    {
        /// \brief Elementwise multiplication operation.
        class Multiply : public util::BinaryElementwiseArithmetic
        {
        public:
            NGRAPH_API
            static constexpr NodeTypeInfo type_info{"Multiply", 0};
            const NodeTypeInfo& get_type_info() const override { return type_info; }
            /// \brief Constructs a multiplication operation.
            Multiply() = default;
            /// \brief Constructs a multiplication operation.
            ///
            /// \param arg0 Node that produces the first input tensor.
            /// \param arg1 Node that produces the second input tensor.
            /// \param auto_broadcast Auto broadcast specification
            Multiply(const Output<Node>& arg0,
                     const Output<Node>& arg1,
                     const AutoBroadcastSpec& auto_broadcast = AutoBroadcastSpec());

            virtual std::shared_ptr<Node>
                copy_with_new_args(const NodeVector& new_args) const override;

            virtual bool is_commutative() const override { return true; }
        protected:
            virtual void generate_adjoints(autodiff::Adjoints& adjoints,
                                           const NodeVector& deltas) override;
        };

        namespace v1
        {
            using op::Multiply;
        }
    };

    std::shared_ptr<Node> operator*(const Output<Node>& arg0, const Output<Node>& arg1);
}
