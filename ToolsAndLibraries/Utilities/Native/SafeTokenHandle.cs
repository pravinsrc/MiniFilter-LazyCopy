// --------------------------------------------------------------------------------------------------------------------
// <copyright file="SafeTokenHandle.cs">
//   The MIT License (MIT)
//   Copyright (c) 2015 Aleksey Kabanov
// </copyright>
// <summary>
//   Permission is hereby granted, free of charge, to any person obtaining a copy
//   of this software and associated documentation files (the "Software"), to deal
//   in the Software without restriction, including without limitation the rights
//   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//   copies of the Software, and to permit persons to whom the Software is
//   furnished to do so, subject to the following conditions:
//
//   The above copyright notice and this permission notice shall be included in
//   all copies or substantial portions of the Software.
//
//   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//   THE SOFTWARE.
// </summary>
// --------------------------------------------------------------------------------------------------------------------

namespace LazyCopy.Utilities.Native
{
    using Microsoft.Win32.SafeHandles;

    /// <summary>
    /// Represents a wrapper class for a find handle used by the <see cref="NativeMethods.OpenProcessToken"/> function.
    /// </summary>
    internal sealed class SafeTokenHandle : SafeHandleZeroOrMinusOneIsInvalid
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="SafeTokenHandle"/> class.
        /// </summary>
        public SafeTokenHandle()
            : base(true)
        {
            // Do nothing.
        }

        /// <summary>
        /// When overridden in a derived class, executes the code required to free the handle.
        /// </summary>
        /// <returns>
        /// <see langword="true"/> if the handle is released successfully; otherwise, in the event of a catastrophic failure, <see langword="false"/>.
        /// </returns>
        protected override bool ReleaseHandle()
        {
            return NativeMethods.CloseHandle(this.handle);
        }
    }
}
