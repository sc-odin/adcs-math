#include <iostream>
#include <memory>

#include "matplotlibcpp.h"
#include "open3d/Open3D.h"

namespace plt = matplotlibcpp;

int main(int argc, char *argv[]) {
    plt::plot({1,3,2,4});
    plt::show();

    using namespace open3d;

    utility::SetVerbosityLevel(utility::VerbosityLevel::Debug);
    if (argc < 3) {
        utility::LogInfo("Open3D {}\n", OPEN3D_VERSION);
        utility::LogInfo("\n");
        utility::LogInfo("Usage:\n");
        utility::LogInfo("    > TestVisualizer [mesh|pointcloud] [filename]\n");
        // CI will execute this file without input files, return 0 to pass
        return 0;
    }

    std::string option(argv[1]);
    if (option == "mesh") {
        auto mesh_ptr = std::make_shared<geometry::TriangleMesh>();
        if (io::ReadTriangleMesh(argv[2], *mesh_ptr)) {
            utility::LogInfo("Successfully read {}\n", argv[2]);
        } else {
            utility::LogWarning("Failed to read {}\n\n", argv[2]);
            return 1;
        }
        mesh_ptr->ComputeVertexNormals();
        visualization::DrawGeometries({mesh_ptr}, "Mesh", 1600, 900);
    } else if (option == "pointcloud") {
        auto cloud_ptr = std::make_shared<geometry::PointCloud>();
        if (io::ReadPointCloud(argv[2], *cloud_ptr)) {
            utility::LogInfo("Successfully read {}\n", argv[2]);
        } else {
            utility::LogWarning("Failed to read {}\n\n", argv[2]);
            return 1;
        }
        cloud_ptr->NormalizeNormals();
        visualization::DrawGeometries({cloud_ptr}, "PointCloud", 1600, 900);
    } else {
        utility::LogWarning("Unrecognized option: {}\n", option);
        return 1;
    }
    utility::LogInfo("End of the test.\n");

    return 0;
}