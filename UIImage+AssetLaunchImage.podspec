Pod::Spec.new do |s|
s.name = "UIImage+AssetLaunchImage"
s.version = "1.0.1"
s.summary = "Adds category methods to UIImage for simple access to launch image."
s.homepage = "https://github.com/TimurBK/UIImage-XCAssets"
s.license = { :type => 'MIT', :file => 'LICENSE' }
s.author = 'Timur Kuchkarov'
s.source = { :git => "https://github.com/TimurBK/UIImage-XCAssets.git", :tag => s.version.to_s }
s.ios.deployment_target = '7.0'
s.source_files = '*.{h,m}'
s.requires_arc = true
end