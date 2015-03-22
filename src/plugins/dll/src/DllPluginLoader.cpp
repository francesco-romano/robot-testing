// -*- mode:C++ { } tab-width:4 { } c-basic-offset:4 { } indent-tabs-mode:nil -*-

/*
 * Copyright (C) 2015 iCub Facility
 * Authors: Ali Paikan
 * CopyPolicy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT
 *
 */

#include <Plugin.h>
#include <DllPluginLoader.h>
#include <DllPluginLoader_impl.h>

using namespace std;
using namespace RTF;
using namespace RTF::plugin;
using namespace shlibpp;

/**
 * @brief DllPluginLoader
 */
DllPluginLoader::DllPluginLoader()
    : implementaion(NULL) { }

DllPluginLoader::~DllPluginLoader() {
    close();
}

void DllPluginLoader::close() {
    if(implementaion)
        delete ((DllPluginLoaderImpl<TestCase>*)implementaion);
    implementaion = NULL;
}

TestCase* DllPluginLoader::open(const std::string filename) {
    close();
    implementaion = new DllPluginLoaderImpl<TestCase>();
    return ((DllPluginLoaderImpl<TestCase>*)implementaion)->open(filename,
                                                                 RTF_PLUGIN_FACTORY_NAME);
}

const std::string DllPluginLoader::getLastError() {
    if(implementaion)
        return ((DllPluginLoaderImpl<TestCase>*)implementaion)->getLastError();
    return string("");
}
