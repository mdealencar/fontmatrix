# Finds the International Components for Unicode (ICU) Library
#
#  ICU_FOUND          - True if ICU found.
#  ICU_I18N_FOUND     - True if ICU's internationalization library found.
#  ICU_INCLUDE_DIRS   - Directory to include to get ICU headers
#                       Note: always include ICU headers as, e.g., 
#                       unicode/utypes.h
#  ICU_LIBRARIES      - Libraries to link against for the common ICU
#  ICU_I18N_LIBRARIES - Libraries to link against for ICU internationaliation
#                       (note: in addition to ICU_LIBRARIES)

# Look for the header file.
# find_path(
#   ICU_INCLUDE_DIR 
#   NAMES unicode/utypes.h
#   DOC "Include directory for the ICU library")
# mark_as_advanced(ICU_INCLUDE_DIR)

# This is a perverted FindICU since we rather look for ICU Layout module
FIND_PATH(
ICU_INCLUDE_DIR 
NAMES layout/LayoutEngine.h
DOC "Include directory for the ICU Layout library"
)
mark_as_advanced(ICU_INCLUDE_DIR)


# Look for the library.
find_library(
  ICU_LIBRARY
  NAMES icule cygicule cygicule32
  DOC "Libraries to link against for the common parts of ICU")
mark_as_advanced(ICU_LIBRARY)

# Look for the library. Again
find_library(
  ICUX_LIBRARY
  NAMES iculx
  DOC "Libraries to link against for the common parts of ICU X")
mark_as_advanced(ICUX_LIBRARY)

# Look for the library. Again
find_library(
  ICUUC_LIBRARY
  NAMES icuuc
  DOC "Libraries to link against for the common parts of ICU X")
mark_as_advanced(ICUUC_LIBRARY)

# Copy the results to the output variables.
if(ICU_INCLUDE_DIR AND ICU_LIBRARY AND ICUX_LIBRARY AND ICUUC_LIBRARY)
  set(ICU_FOUND 1)
  set(ICU_LIBRARIES ${ICU_LIBRARY} ${ICUX_LIBRARY} ${ICUUC_LIBRARY})
  set(ICU_INCLUDE_DIRS ${ICU_INCLUDE_DIR})

  # Look for the ICU internationalization libraries
  find_library(
    ICU_I18N_LIBRARY
    NAMES icuin icui18n cygicuin cygicuin32
    DOC "Libraries to link against for ICU internationalization")
  mark_as_advanced(ICU_I18N_LIBRARY)
  if (ICU_I18N_LIBRARY)
    set(ICU_I18N_FOUND 1)
    set(ICU_I18N_LIBRARIES ${ICU_I18N_LIBRARY})
  else (ICU_I18N_LIBRARY)
    set(ICU_I18N_FOUND 0)
    set(ICU_I18N_LIBRARIES)
  endif (ICU_I18N_LIBRARY)
else(ICU_INCLUDE_DIR AND ICU_LIBRARY)
  set(ICU_FOUND 0)
  set(ICU_I18N_FOUND 0)
  set(ICU_LIBRARIES)
  set(ICU_I18N_LIBRARIES)
  set(ICU_INCLUDE_DIRS)
endif(ICU_INCLUDE_DIR AND ICU_LIBRARY AND ICUX_LIBRARY AND ICUUC_LIBRARY)

