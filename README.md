# Package Support Framework
This project provides tools, libraries, documentation and samples for creating app-compat fixups to enable classic Win32 applications to be distributed and executed as packaged apps.

## Documentation
Check out our [step by step guide](https://docs.microsoft.com/en-us/windows/uwp/porting/package-support-framework), it will walk you through the main PSF workflows and provides the key documentation.

See also:
* [Package Support Framework package layout](layout.md)
* [Package Support Framework Nuget package install](https://www.nuget.org/packages/Microsoft.PackageSupportFramework)
* [Instructions for authoring your own shim dll](Authoring.md)

## [License](https://github.com/Microsoft/MSIX-PackageSupportFramework/blob/master/LICENSE)
Code licensed under the [MIT License](https://github.com/Microsoft/MSIX-PackageSupportFramework/blob/master/LICENSE).

## Branch structure
Package Support Framework adopts a development and master branching style.

### Master
This branch represents the source in the most recent nuget package.  The code in this branch is the most stable.  Please do not fork off this branch for development.

### Develop
This branch has the latest code. Keep in mind that there might be features in this branch that is not yet in master.  Please make a private fork off this branch to make any contributions to Package Support Framework.

## Contribute
This project welcomes contributions and suggestions.  Most contributions require you to agree to a Contributor License Agreement (CLA) declaring that you have the right to, and actually do, grant us the rights to use your contribution. For details, visit https://cla.microsoft.com.

## Fixup Metadata
Each fixup and the PSF Launcher has a metadata file in xml format.  Each file contains the following  
 1. Version:  The version of the PSF is in MAJOR.MINOR.PATCH format according to [Sem Version 2](https://semver.org/)
 2. Minimum Windows Platform the the minimum windows version required for the fixup or PSF Launcher.
 3. Description: Short description of the Fixup.
 4. WhenToUse: Heuristics on when you should apply the fixup.

Addtionally, we have the XSD for the metadata files.  THe XSD is located in the solution folder.

Submit your own fixup(s) to the community:
1. Create a private fork for yourself
2. Make your changes in your private branch
3. For new files that you are adding include the following Copyright statement.\
//-------------------------------------------------------------------------------------------------------\
// Copyright (c) #YOUR NAME#. All rights reserved.\
// Licensed under the MIT license. See LICENSE file in the project root for full license information.\
//-------------------------------------------------------------------------------------------------------
4. Create a pull request into 'fork:Microsoft/MSIX-PackageSupportFramework' 'base:develop'

When you submit a pull request, a CLA-bot will automatically determine whether you need to provide a CLA and decorate the PR appropriately (e.g., label, comment). Simply follow the instructions provided by the bot. You will only need to do this once across all repos using our CLA.

Here is how you can contribute to the Package Support Framework:

* [Submit bugs](https://github.com/Microsoft/MSIX-PackageSupportFramework/issues) and help us verify fixes
* [Submit pull requests](https://github.com/Microsoft/MSIX-PackageSupportFramework/pulls) for bug fixes and features and discuss existing proposals

This project has adopted the [Microsoft Open Source Code of Conduct](https://opensource.microsoft.com/codeofconduct/). For more information see the [Code of Conduct FAQ](https://opensource.microsoft.com/codeofconduct/faq/) or contact [opencode@microsoft.com](mailto:opencode@microsoft.com) with any additional questions or comments.

## Data/Telemetry
Telemetry datapoint has been hooked to collect usage data and sends it to Microsoft to help improve our products and services. Read Microsoft's [privacy statement to learn more](https://privacy.microsoft.com/en-US/privacystatement). However, Data will be collected only when the PSF binaries are used from [Nuget package](https://www.nuget.org/packages?q=packagesupportframework). 
Nuget package has the binaries signed and will collect usage data from machine. When the binaries are built locally by cloning the repo or downloading the bits, then telemetry is not collected.