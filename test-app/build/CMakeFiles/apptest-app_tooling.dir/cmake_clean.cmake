file(REMOVE_RECURSE
  "test-app/main.qml"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/apptest-app_tooling.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
