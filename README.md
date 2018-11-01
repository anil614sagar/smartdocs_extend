# smartdocs_extend
Apigee Drupal Developer Portal SmartDocs Extension Module which fixes critical issues with smartdocs.


# Installation Instructions

* Download the entire folder as zip files
* Extract the zip file in sites/all/modules/custom directory inside your Drupal Root.
* Make sure smartdocs_extend.module file exist in sites/all/modules/custom/smartdocs_extend directory.
* Navigate to admin/modules
* Search for Smartdocs Extension module
* Enable the module
* Clear all caches.



## Version 7.x-1.0 - Release - Features

* Ability to download original specification.
  * Navigate to SmartDocs revision to see Download Original Spec button.
* If uploaded specification is JSON Open API Spec, Entire specification related to a particular API Method is available as JavaScript variable for the smartdocs template along with full definitions of OpenAPI Specification.
  * Look for api_raw_spec variable in javascript.
* Fix for sample request payload rendering for POST / PUT operation.
   * Sample Request Payload rendering fails if OpenAPI Spec contains parameter object which inturn contains parameters.
* Fix for deafult values rendering inside sample payload request.
   * If default value of property is mentioned using "example" or "default" key in Open API Spec, Request Payload generated will render same.



## Have a Question / Feedback ?

https://community.apigee.com
https://community.apigee.com/articles/49980/smartdocs-alternative-to-swagger-ui-great-features.html
https://community.apigee.com/articles/50017/smartdocs-a-custom-module-to-your-rescue-fix-for-c.html

