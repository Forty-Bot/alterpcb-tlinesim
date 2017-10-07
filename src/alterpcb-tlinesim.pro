QT += core gui

TARGET = alterpcb-tlinesim
TEMPLATE = app

LIBS += -lcholmod

INCLUDEPATH += common gui simulation
DEPENDPATH += common gui simulation

QMAKE_CXXFLAGS += -std=c++11 -Wconversion
QMAKE_CXXFLAGS_RELEASE += -DNDEBUG
QMAKE_CXXFLAGS_RELEASE -= -g

########## Warning: Everything below this line is auto-generated and will be overwritten! ##########

HEADERS += \
	common/Basics.h \
	common/Color.h \
	common/ColorMap.h \
	common/Cow.h \
	common/Decimal.h \
	common/EnumTranslator.h \
	common/HashTable.h \
	common/Json.h \
	common/MiscMath.h \
	common/MurmurHash.h \
	common/NaturalSort.h \
	common/StringHelper.h \
	common/StringRegistry.h \
	common/VData.h \
	common/VDataPath.h \
	common/Vector.h \
	gui/ApplicationDirs.h \
	gui/GlobalDirs.h \
	gui/Icons.h \
	gui/LayoutHelper.h \
	gui/MainWindow.h \
	gui/MeshViewer.h \
	gui/QLineEditSmall.h \
	gui/Qt.h \
	simulation/CholmodSolver.h \
	simulation/FindRoot.h \
	simulation/GenericMesh.h \
	simulation/GridMesh2D.h \
	simulation/MaterialDatabase.h \
	simulation/SparseMatrix.h \
	simulation/TLineTypes.h

SOURCES += \
	Main.cpp \
	common/Color.cpp \
	common/ColorMap.cpp \
	common/Decimal.cpp \
	common/Json.cpp \
	common/NaturalSort.cpp \
	common/StringRegistry.cpp \
	common/VData.cpp \
	gui/ApplicationDirs.cpp \
	gui/Icons.cpp \
	gui/MainWindow.cpp \
	gui/MeshViewer.cpp \
	gui/QLineEditSmall.cpp \
	simulation/CholmodSolver.cpp \
	simulation/GenericMesh.cpp \
	simulation/GridMesh2D.cpp \
	simulation/MaterialDatabase.cpp \
	simulation/SparseMatrix.cpp \
	simulation/TLineTypes.cpp \
	simulation/TLine_CoplanarWaveguide.cpp \
	simulation/TLine_Microstrip.cpp