#include "3rd_party/CLI11.hpp"
#include "Argument.hpp"
#include "Drawer.hpp"

Argument::Argument(const int &argc, char **argv)
{
    CLI::App app{"Funny JSON Explorer (FJE) is a command line interface tool for visualizing JSON files"};
    argv = app.ensure_utf8(argv);

    auto JsonFileOption = app.add_option("-f", JsonFile, "The JSON file to be visualized");
    JsonFileOption->required();
    JsonFileOption->check(CLI::ExistingFile);
    auto StyleOption = app.add_option("-s", style, "Choose an output style");
    StyleOption->default_val("tree");
    StyleOption->check(CLI::IsMember(Drawer::GetAvailableDrawerName()));
    auto IconFamilyConfFileOption = app.add_option("-i", IconFamilyConfFile, "Path to the icon family configuration file");
    IconFamilyConfFileOption->check(CLI::ExistingFile);

    try {
        app.parse(argc, argv);
    } catch (const CLI::ParseError &e) {
        exit(app.exit(e));
    }
}