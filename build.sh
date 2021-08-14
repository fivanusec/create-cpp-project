RED="\e[31m"
GREEN="\e[32m"
ENDCOLOR="\e[0m"

cmake -B build
cd build
make

if [ $? -eq 0 ]; then
   echo -e "${GREEN}create-cpp-project build successfully${ENDCOLOR}"
else
   echo -e "${RED}There was a problem while building create-cpp-project ${ENDCOLOR}"
fi