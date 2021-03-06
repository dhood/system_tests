// Copyright 2015 Open Source Robotics Foundation, Inc.
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

#ifndef MESSAGE_FIXTURES_HPP_
#define MESSAGE_FIXTURES_HPP_

#include <cassert>
#include <limits>
#include <vector>

#include "test_communication/msg/builtins.hpp"
#include "test_communication/msg/dynamic_array_nested.hpp"
#include "test_communication/msg/dynamic_array_primitives.hpp"
#include "test_communication/msg/empty.hpp"
#include "test_communication/msg/nested.hpp"
#include "test_communication/msg/primitives.hpp"
#include "test_communication/msg/static_array_nested.hpp"
#include "test_communication/msg/static_array_primitives.hpp"


std::vector<test_communication::msg::Empty::SharedPtr>
get_messages_empty()
{
  std::vector<test_communication::msg::Empty::SharedPtr> messages;
  auto msg = std::make_shared<test_communication::msg::Empty>();
  messages.push_back(msg);
  return messages;
}

std::vector<test_communication::msg::Primitives::SharedPtr>
get_messages_primitives()
{
  std::vector<test_communication::msg::Primitives::SharedPtr> messages;
  {
    auto msg = std::make_shared<test_communication::msg::Primitives>();
    msg->bool_value = false;
    msg->byte_value = 0;
    msg->char_value = '\0';
    msg->float32_value = 0.0f;
    msg->float64_value = 0;
    msg->int8_value = 0;
    msg->uint8_value = 0;
    msg->int16_value = 0;
    msg->uint16_value = 0;
    msg->int32_value = 0;
    msg->uint32_value = 0;
    msg->int64_value = 0;
    msg->uint64_value = 0;
    msg->string_value = "";
    messages.push_back(msg);
  }
  {
    auto msg = std::make_shared<test_communication::msg::Primitives>();
    msg->bool_value = true;
    msg->byte_value = 255;
    msg->char_value = '\255';
    msg->float32_value = 1.11f;
    msg->float64_value = 1.11;
    msg->int8_value = (std::numeric_limits<int8_t>::max)();
    msg->uint8_value = (std::numeric_limits<uint8_t>::max)();
    msg->int16_value = (std::numeric_limits<int16_t>::max)();
    msg->uint16_value = (std::numeric_limits<uint16_t>::max)();
    msg->int32_value = (std::numeric_limits<int32_t>::max)();
    msg->uint32_value = (std::numeric_limits<uint32_t>::max)();
    msg->int64_value = (std::numeric_limits<int64_t>::max)();
    msg->uint64_value = (std::numeric_limits<uint64_t>::max)();
    msg->string_value = "max value";
    messages.push_back(msg);
  }
  {
    auto msg = std::make_shared<test_communication::msg::Primitives>();
    msg->bool_value = false;
    msg->byte_value = 0;
    msg->char_value = 0x0;
    msg->float32_value = -2.22f;
    msg->float64_value = -2.22;
    msg->int8_value = (std::numeric_limits<int8_t>::min)();
    msg->uint8_value = 0;
    msg->int16_value = (std::numeric_limits<int16_t>::min)();
    msg->uint16_value = 0;
    msg->int32_value = (std::numeric_limits<int32_t>::min)();
    msg->uint32_value = 0;
    msg->int64_value = (std::numeric_limits<int64_t>::min)();
    msg->uint64_value = 0;
    msg->string_value = "min value";
    messages.push_back(msg);
  }
  {
    auto msg = std::make_shared<test_communication::msg::Primitives>();
    msg->bool_value = true;
    msg->byte_value = 1;
    msg->char_value = '\1';
    msg->float32_value = 1.0f;
    msg->float64_value = 1;
    msg->int8_value = 1;
    msg->uint8_value = 1;
    msg->int16_value = 1;
    msg->uint16_value = 1;
    msg->int32_value = 1;
    msg->uint32_value = 1;
    msg->int64_value = 1;
    msg->uint64_value = 1;
    // check strings longer then 255 characters
    msg->string_value = "";
    for (size_t i = 0; i < 256; ++i) {
      msg->string_value += std::to_string(i % 10);
    }
    messages.push_back(msg);
  }
  return messages;
}

std::vector<test_communication::msg::StaticArrayPrimitives::SharedPtr>
get_messages_static_array_primitives()
{
  std::vector<test_communication::msg::StaticArrayPrimitives::SharedPtr> messages;
  {
    auto msg = std::make_shared<test_communication::msg::StaticArrayPrimitives>();
    msg->bool_values = {{false, true, false}};
    msg->byte_values = {{0, 0xff, 0}};
    msg->char_values = {{'\0', '\255', '\0'}};
    msg->float32_values = {{0.0f, 1.11f, -2.22f}};
    msg->float64_values = {{0, 1.11, -2.22}};
    // *INDENT-OFF* (prevent uncrustify from making unecessary indents here)
    msg->int8_values = {{
      0, (std::numeric_limits<int8_t>::max)(), (std::numeric_limits<int8_t>::min)()}};
    msg->uint8_values = {{0, (std::numeric_limits<uint8_t>::max)(), 0}};
    msg->int16_values = {{
      0, (std::numeric_limits<int16_t>::max)(), (std::numeric_limits<int16_t>::min)()}};
    msg->uint16_values = {{0, (std::numeric_limits<uint16_t>::max)(), 0}};
    msg->int32_values = {{
      static_cast<int32_t>(0),
      (std::numeric_limits<int32_t>::max)(),
      (std::numeric_limits<int32_t>::min)()
    }};
    // *INDENT-ON*
    msg->uint32_values = {{0, (std::numeric_limits<uint32_t>::max)(), 0}};
    msg->int64_values[0] = 0;
    msg->int64_values[1] = (std::numeric_limits<int64_t>::max)();
    msg->int64_values[2] = (std::numeric_limits<int64_t>::min)();
    msg->uint64_values = {{0, (std::numeric_limits<uint64_t>::max)(), 0}};
    msg->string_values = {{"", "max value", "min value"}};
    messages.push_back(msg);
  }
  return messages;
}

std::vector<test_communication::msg::DynamicArrayPrimitives::SharedPtr>
get_messages_dynamic_array_primitives()
{
  std::vector<test_communication::msg::DynamicArrayPrimitives::SharedPtr> messages;
  {
    auto msg = std::make_shared<test_communication::msg::DynamicArrayPrimitives>();
    msg->bool_values = {{}};
    msg->byte_values = {{}};
    msg->char_values = {{}};
    msg->float32_values = {{}};
    msg->float64_values = {{}};
    msg->int8_values = {{}};
    msg->uint8_values = {{}};
    msg->int16_values = {{}};
    msg->uint16_values = {{}};
    msg->int32_values = {{}};
    msg->uint32_values = {{}};
    msg->int64_values = {{}};
    msg->uint64_values = {{}};
    msg->string_values = {{}};
    msg->check = 0;
    messages.push_back(msg);
  }
  {
    auto msg = std::make_shared<test_communication::msg::DynamicArrayPrimitives>();
    msg->bool_values = {true};
    msg->byte_values = {0xff};
    msg->char_values = {'\255'};
    msg->float32_values = {1.11f};
    msg->float64_values = {1.11};
    msg->int8_values = {(std::numeric_limits<int8_t>::max)()};
    msg->uint8_values = {(std::numeric_limits<uint8_t>::max)()};
    msg->int16_values = {(std::numeric_limits<int16_t>::max)()};
    msg->uint16_values = {(std::numeric_limits<uint16_t>::max)()};
    msg->int32_values = {(std::numeric_limits<int32_t>::max)()};
    msg->uint32_values = {(std::numeric_limits<uint32_t>::max)()};
    msg->int64_values = {(std::numeric_limits<int64_t>::max)()};
    msg->uint64_values = {(std::numeric_limits<uint64_t>::max)()};
    msg->string_values = {{"max value"}};
    msg->check = 1;
    messages.push_back(msg);
  }
  {
    auto msg = std::make_shared<test_communication::msg::DynamicArrayPrimitives>();
    msg->bool_values = {{false, true}};
    msg->byte_values = {{0, 0xff}};
    msg->char_values = {{'\0', '\255'}};
    msg->float32_values = {{0.0f, 1.11f, -2.22f}};
    msg->float64_values = {{0, 1.11, -2.22}};
    // *INDENT-OFF* (prevent uncrustify from making unecessary indents here)
    msg->int8_values = {{
      0, (std::numeric_limits<int8_t>::max)(), (std::numeric_limits<int8_t>::min)()}};
    msg->uint8_values = {{0, (std::numeric_limits<uint8_t>::max)()}};
    msg->int16_values = {{
      0, (std::numeric_limits<int16_t>::max)(), (std::numeric_limits<int16_t>::min)()}};
    msg->uint16_values = {{0, (std::numeric_limits<uint16_t>::max)()}};
    // The narrowing static cast is required to avoid build errors on Windows.
    msg->int32_values = {{
      static_cast<int32_t>(0),
      (std::numeric_limits<int32_t>::max)(),
      (std::numeric_limits<int32_t>::min)()
    }};
    // *INDENT-ON*
    msg->uint32_values = {{0, (std::numeric_limits<uint32_t>::max)()}};
    msg->int64_values.resize(3);
    msg->int64_values[0] = 0;
    msg->int64_values[1] = (std::numeric_limits<int64_t>::max)();
    msg->int64_values[2] = (std::numeric_limits<int64_t>::min)();
    msg->uint64_values = {{0, (std::numeric_limits<uint64_t>::max)()}};
    msg->string_values = {{"", "max value", "optional min value"}};
    msg->check = 2;
    messages.push_back(msg);
  }
  {
    auto msg = std::make_shared<test_communication::msg::DynamicArrayPrimitives>();
    // check sequences with more then 100 elements
    const size_t size = 101;
    msg->bool_values.resize(size);
    msg->byte_values.resize(size);
    msg->char_values.resize(size);
    msg->float32_values.resize(size);
    msg->float64_values.resize(size);
    msg->int8_values.resize(size);
    msg->uint8_values.resize(size);
    msg->int16_values.resize(size);
    msg->uint16_values.resize(size);
    msg->int32_values.resize(size);
    msg->uint32_values.resize(size);
    msg->int64_values.resize(size);
    msg->uint64_values.resize(size);
    msg->string_values.resize(size);
    for (size_t i = 0; i < size; ++i) {
      msg->bool_values[i] = (i % 2 != 0) ? true : false;
      msg->byte_values[i] = static_cast<uint8_t>(i);
      msg->char_values[i] = static_cast<char>(i);
      msg->float32_values[i] = 1.1f * i;
      msg->float64_values[i] = 1.1 * i;
      msg->int8_values[i] = static_cast<int8_t>(i);
      msg->uint8_values[i] = static_cast<uint8_t>(i);
      msg->int16_values[i] = static_cast<int16_t>(i);
      msg->uint16_values[i] = static_cast<uint16_t>(i);
      msg->int32_values[i] = static_cast<int32_t>(i);
      msg->uint32_values[i] = static_cast<uint32_t>(i);
      msg->int64_values[i] = i;
      msg->uint64_values[i] = i;
      msg->string_values[i] = std::to_string(i);
    }
    msg->check = 3;
    messages.push_back(msg);
  }
  {
    auto msg = std::make_shared<test_communication::msg::DynamicArrayPrimitives>();
    // check default sequences
    msg->check = 4;
    messages.push_back(msg);
  }
  return messages;
}

std::vector<test_communication::msg::Nested::SharedPtr>
get_messages_nested()
{
  std::vector<test_communication::msg::Nested::SharedPtr> messages;
  auto primitive_msgs = get_messages_primitives();
  for (auto primitive_msg : primitive_msgs) {
    auto msg = std::make_shared<test_communication::msg::Nested>();
    msg->primitive_values = *primitive_msg;
    messages.push_back(msg);
  }
  return messages;
}

std::vector<test_communication::msg::DynamicArrayNested::SharedPtr>
get_messages_dynamic_array_nested()
{
  std::vector<test_communication::msg::DynamicArrayNested::SharedPtr> messages;
  {
    auto msg = std::make_shared<test_communication::msg::DynamicArrayNested>();
    auto primitive_msgs = get_messages_primitives();
    for (auto primitive_msg : primitive_msgs) {
      msg->primitive_values.push_back(*primitive_msg);
    }
    messages.push_back(msg);
  }
  return messages;
}

std::vector<test_communication::msg::StaticArrayNested::SharedPtr>
get_messages_static_array_nested()
{
  std::vector<test_communication::msg::StaticArrayNested::SharedPtr> messages;
  {
    auto msg = std::make_shared<test_communication::msg::StaticArrayNested>();
    auto primitive_msgs = get_messages_primitives();
    assert(primitive_msgs.size() == msg->primitive_values.size());
    size_t i = 0;
    for (auto primitive_msg : primitive_msgs) {
      msg->primitive_values[i] = *primitive_msg;
      ++i;
    }
    messages.push_back(msg);
  }
  return messages;
}

std::vector<test_communication::msg::Builtins::SharedPtr>
get_messages_builtins()
{
  std::vector<test_communication::msg::Builtins::SharedPtr> messages;
  {
    auto msg = std::make_shared<test_communication::msg::Builtins>();
    msg->duration_value.sec = -1234567890;
    msg->duration_value.nanosec = 123456789;
    msg->time_value.sec = -1234567890;
    msg->time_value.nanosec = 987654321;
    messages.push_back(msg);
  }
  return messages;
}

#endif  // MESSAGE_FIXTURES_HPP_
