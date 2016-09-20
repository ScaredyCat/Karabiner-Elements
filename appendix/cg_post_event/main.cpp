#include <CoreGraphics/CoreGraphics.h>
#include <chrono>
#include <thread>

int main(int argc, const char* argv[]) {
  while (true) {
    // shift key
    {
      auto ev = CGEventCreateKeyboardEvent(nullptr, (CGKeyCode)56, true);
      CGEventSetFlags(ev, static_cast<CGEventFlags>(kCGEventFlagMaskShift | CGEventGetFlags(ev)));
      CGEventPost(kCGHIDEventTap, ev);
      CFRelease(ev);
    }

    // We have to put wait between continous CGEventPost.
    std::this_thread::sleep_for(std::chrono::milliseconds(10));

    // z key
    {
      auto ev = CGEventCreateKeyboardEvent(nullptr, (CGKeyCode)6, true);
      CGEventSetFlags(ev, static_cast<CGEventFlags>(kCGEventFlagMaskShift | CGEventGetFlags(ev)));
      CGEventPost(kCGHIDEventTap, ev);
      CFRelease(ev);
    }

    // We have to put wait between continous CGEventPost.
    std::this_thread::sleep_for(std::chrono::milliseconds(1));

    {
      auto ev = CGEventCreateKeyboardEvent(nullptr, (CGKeyCode)6, false);
      CGEventSetFlags(ev, static_cast<CGEventFlags>(kCGEventFlagMaskShift | CGEventGetFlags(ev)));
      CGEventPost(kCGHIDEventTap, ev);
      CFRelease(ev);
    }

    // We have to put wait between continous CGEventPost.
    std::this_thread::sleep_for(std::chrono::seconds(3));

    // shift key
    {
      auto ev = CGEventCreateKeyboardEvent(nullptr, (CGKeyCode)56, false);
      CGEventPost(kCGHIDEventTap, ev);
      CFRelease(ev);
    }

    // We have to put wait between continous CGEventPost.
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
  }

  return 0;
}
