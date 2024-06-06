#include "3rd_party/CLI11.hpp"
#include "Argument.hpp"
#include "Drawer.hpp"

Argument::Argument(const int &argc, char **argv)
{
    CLI::App app{"Funny JSON Explorer (FJE) is a command line interface tool for visualizing JSON files"};
    argv = app.ensure_utf8(argv);

    CLI::Option *json_file_option = app.add_option("-f", json_file, "The JSON file to be visualized");
    json_file_option->required();
    json_file_option->check(CLI::ExistingFile);
    CLI::Option *style_option = app.add_option("-s", style, "Choose an output style");
    style_option->required();
    style_option->check(CLI::IsMember(Drawer::GetAvailableDrawerName()));
    CLI::Option *icon_family_option = app.add_option("-i", icon_family, "Path to the icon family configuration file");
    icon_family_option->check(CLI::ExistingFile);

    try {
        app.parse(argc, argv);
    } catch (const CLI::ParseError &e) {
        exit(app.exit(e));
    }
}