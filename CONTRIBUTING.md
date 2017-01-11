# Contributing

General guidelines for contributing to geometry.hpp

## Releasing

To release a new geometry.hpp version:

 - Make sure that all tests are passing (including travis tests).
 - Update the CHANGELOG.md
 - Make a "bump commit" by updating the version in `package.json` and adding a commit like `-m "bump to v0.8.5"`
 - Create a github tag like `git tag -a v0.9.0 -m "v0.9.0" && git push --tags`
 - Ensure you have a clean checkout (no extra files in your check that are not known by git). You need to be careful, for instance, to avoid a large accidental file being packaged by npm.
  - Then publish the module to npm repositories by running `npm publish`
