#include <filesystem>
#include <iostream>
#include <unordered_set>

void file_merger_single(std::filesystem::path orig,
                        std::filesystem::path dest) {
    for (const std::filesystem::directory_entry& orig_file :
         std::filesystem::recursive_directory_iterator(orig)) {
        std::filesystem::path file_rel;
        if (!is_regular_file(orig_file.path())) continue;

        // origからの相対パス化してdestにつける
        auto it = orig.begin();
        for (const auto& eachlev : orig_file.path()) {
            if (eachlev == *it) {
                it++;
            } else {
                file_rel /= eachlev;
            }
        }
        std::filesystem::path dest_file = dest / file_rel;

        std::cout << orig_file.path() << " -> " << dest_file << std::endl;
        if (!std::filesystem::exists(dest_file.parent_path()))
            std::filesystem::create_directories(dest_file.parent_path());
        std::filesystem::rename(orig_file.path(), dest_file);
    }
}

void file_merger_multiple(std::filesystem::path unmerged,
                          std::filesystem::path merged) {
    for (const std::filesystem::directory_entry& eachdir :
         std::filesystem::directory_iterator(unmerged)) {
        if (!std::filesystem::is_directory(eachdir.path())) continue;
        file_merger_single(eachdir.path(), merged);
    }
}

int main() {
    std::filesystem::path orig = "bar";
    std::filesystem::path merged = "hoge";
    file_merger_multiple(orig, merged);
}