set(UI_DIR ./ui)
file(GLOB_RECURSE UI_SOURCES ${UI_DIR}/*.c)

set(MODEL_DIR ./model)
file(GLOB_RECURSE MODEL_SOURCES ${MODEL_DIR}/*.c)

set(VIEW_DIR ./view)
file(GLOB_RECURSE VIEW_SOURCES ${VIEW_DIR}/*.c)

set(CONTROLLER_DIR ./controller)
file(GLOB_RECURSE CONTROLLER_SOURCES ${CONTROLLER_DIR}/*.c)

set(UTIL_DIR ./util)
file(GLOB_RECURSE UTIL_SOURCES ${UTIL_DIR}/*.c)

idf_component_register(
    SRCS "main.c" "lv_port.c" ${UI_SOURCES} ${MODEL_SOURCES} ${VIEW_SOURCES} ${CONTROLLER_SOURCES} ${UTIL_SOURCES}
    INCLUDE_DIRS "."  ${UI_DIR} ${MODEL_DIR} ${VIEW_DIR} ${CONTROLLER_DIR} ${UTIL_DIR}
    EMBED_TXTFILES timeapi_cert.pem)

target_add_binary_data(${COMPONENT_TARGET} "certs/aws_root_ca_pem" TEXT)
target_add_binary_data(${COMPONENT_TARGET} "certs/certificate_pem_crt" TEXT)
target_add_binary_data(${COMPONENT_TARGET} "certs/private_pem_key" TEXT)
