cd or-tools  # Navigate to your OR-Tools clone
mkdir -p build_wasm && cd build_wasm

# Configure with Emscripten
emcmake cmake .. \
  -DCMAKE_CXX_FLAGS="-msimd128" \
  -DABSL_RANDOM_INTERNAL_RANDEN_HWAES_IMPL=OFF \
  -DCMAKE_BUILD_TYPE=Release \
  -DBUILD_DEPS=ON \
  -DBUILD_PYTHON=OFF \
  -DBUILD_JAVA=OFF \
  -DBUILD_EXAMPLES=OFF \
  -DBUILD_SAMPLES=OFF
  
# Compile
emmake make